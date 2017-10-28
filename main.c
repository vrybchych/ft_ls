/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:47:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/28 13:52:49 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// ft_ls /dev

static void	ft_print(char *dir_name, t_e *el)
{
	static int		first_enter;

	if (first_enter)
	{
		write(1, "\n", 1);
		write(1, dir_name, ft_strlen(dir_name));
		write(1, ":\n", 2);
	}
	g_flag_l ? print_total(el) : 0;
	first_enter++;
	while (el)
	{
		g_flag_l ? print_l(el) : 0;
		write(1, el->name, ft_strlen(el->name));
		S_ISLNK(el->st.st_mode) ? print_link(el) : 0;
		write(1, "\n", 1);
		el = el->next;
	}
}

static void	read_dir(DIR *dir_fd, t_e **el, char *dir_name)
{
	struct dirent	*dirp;
	struct stat     st;
	char            s_tmp[PATH_MAX];

	while ((dirp = readdir(dir_fd)))
    {
        if (dirp->d_name[0] == '.' && !g_flag_a)
            continue ;
        if ((!ft_strcmp(dirp->d_name, ".") || !ft_strcmp(dirp->d_name, ".."))
			&& !g_flag_a)
            continue ;
        ft_strcpy(s_tmp, dir_name);
        ft_strcat(s_tmp, "/");
        ft_strcat(s_tmp, dirp->d_name);
		lstat(s_tmp, &st);
        add_to_list(el, st, dirp->d_name, s_tmp);
    }
}

void		ft_ls(char *dir_name, t_e *el)
{
	DIR				*dir_fd;
	t_e				*begin;

	if (!(dir_fd = opendir(dir_name)))
	{
		write(1, "ft_ls: ", 8);
        perror(dir_name);
        return ;
    }
	read_dir(dir_fd, &el, dir_name);
	ft_print(dir_name, el);
	begin = el;
	if (g_flag_R)
		while (el)
		{
			if (ft_strcmp(el->name, ".") && ft_strcmp(el->name, ".."))
			if (S_ISDIR(el->st.st_mode))
        	    ft_ls(el->path, NULL);
			el = el->next;
		}
	free_el(begin);
	closedir(dir_fd);
}

static int	set_flags(char *s)
{
    if (s[0] != '-')
		return (0);
	while (*(++s))
        if (*s == 'R')
			g_flag_R = 1;
		else if (*s == 't')
            g_flag_t = 1;
		else if (*s == 'a')
            g_flag_a = 1;
		else if (*s == 'l')
            g_flag_l = 1;
		else if (*s == 'r')
            g_flag_r = 1;
		else
		{
			write(1, "usage: .ft_ls [-latrR] [file...]\n", 33);
			exit (0);
		}
	return (1);
}

int			main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc == 1)
		ft_ls(".", NULL);
	else
	{
		while (i < argc && set_flags(argv[i]))
			i++;
		if (i >= argc)
			ft_ls(".", NULL);
		else if ((i + 1) == argc)
			ft_ls(argv[i], NULL);
		else
			sort_and_check_argv(argv, i, argc);
	}
	return (0);
}
