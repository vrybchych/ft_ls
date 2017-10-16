/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:47:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/14 14:20:09 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void ft_ls(char *dir_name)
{
	DIR				*dir_fd;
	char			s_tmp[PATH_MAX];
	struct dirent	*dirp;
	struct stat		st;

	dir_fd = opendir(dir_name);
	while ((dirp = readdir(dir_fd)))
	{
		if (!strcmp(dirp->d_name, ".") || !strcmp(dirp->d_name, ".."))
			continue ;
		strcpy(s_tmp, dir_name);
		strcat(s_tmp, "/");
		strcat(s_tmp, dirp->d_name);
		stat(s_tmp, &st);
		if (S_ISDIR(st.st_mode))
			ft_ls(s_tmp);
		printf("%s\n", dirp->d_name);
	}
	closedir(dir_fd);
}

int			main(int argc, char **argv)
{
//	struct stat tmp;
	if (argc > 1)
		ft_ls(argv[1]);
	else
		printf("no arguments\n");
	return (0);
}
