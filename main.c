/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:47:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/24 14:02:43 by vrybchyc         ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	g_flag_l = 1;
	g_flag_R = 1;
	g_flag_a = 0;

	if (argc > 1)
		ft_ls(argv[1], NULL);
	else
		printf("no arguments\n");//test
	return (0);
}
