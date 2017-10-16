/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:47:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/16 15:08:13 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print(t_e *el)
{
	while (el)
	{
		printf("%s\n", el->name);      //test
		el = el->next;
	}
}

static void	ft_ls(char *dir_name, t_e **el)
{
	DIR				*dir_fd;
	char			s_tmp[PATH_MAX];
	struct dirent	*dirp;
	struct stat		st;

	dir_fd = opendir(dir_name);
	while ((dirp = readdir(dir_fd)))
	{
		if (dirp->d_name[0] == '.') //test
			continue ; //test
		if (!ft_strcmp(dirp->d_name, ".") || !ft_strcmp(dirp->d_name, ".."))
			continue ;
		ft_strcpy(s_tmp, dir_name);
		ft_strcat(s_tmp, "/");
		ft_strcat(s_tmp, dirp->d_name);
		stat(s_tmp, &st);
//		add_to_list(el, st, dirp->d_name);
		if (S_ISDIR(st.st_mode))
			ft_ls(s_tmp, el);
		add_to_list(el, st, s_tmp);
//		printf("%s\n", dirp->d_name);//test
	}
	closedir(dir_fd);
}

int			main(int argc, char **argv)
{
	t_e 	*el;

	el = NULL;
	if (argc > 1)
	{
		ft_ls(argv[1], &el);
		ft_print(el);
	}
	else
		printf("no arguments\n");//test
	return (0);
}
