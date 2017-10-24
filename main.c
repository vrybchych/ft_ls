/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:47:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/24 16:18:00 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print(char *dir_name, t_e *el)
{
	if (ft_strcmp(".", dir_name) && g_flag_l)
	{
		write(1, "\n", 1);
		write(1, dir_name, ft_strlen(dir_name));
		write(1, ":\n", 2);
	}
	while (el)
	{
		if (g_flag_l)
			print_l(el);
		write(1, el->name, ft_strlen(el->name));
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
        if (!ft_strcmp(dirp->d_name, ".") || !ft_strcmp(dirp->d_name, ".."))
            continue ;
        ft_strcpy(s_tmp, dir_name);
        ft_strcat(s_tmp, "/");
        ft_strcat(s_tmp, dirp->d_name);
        stat(s_tmp, &st);
        add_to_list(el, st, dirp->d_name, s_tmp);
    }
}


static void	ft_ls(char *dir_name, t_e *el)
{
	DIR				*dir_fd;

	if (!(dir_fd = opendir(dir_name)))
	{
		write(1, "ft_ls:", 7);
        perror(dir_name);
        return ;
    }
	read_dir(dir_fd, &el, dir_name);
	ft_print(dir_name, el);
	if (g_flag_R)
		while (el)
		{
			if (S_ISDIR(el->st.st_mode))
        	    ft_ls(el->path, NULL);
			el = el->next;
		}
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
		else
			while (i < argc)
				ft_ls(argv[i++], NULL);
	}
	return (0);
}
