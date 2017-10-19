/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:47:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/19 19:19:24 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print(char *dir_name, t_e *el)
{
	if (ft_strcmp(".", dir_name))
	{
		write(1, "\n", 1);
		write(1, dir_name, ft_strlen(dir_name));
		write(1, ":\n", 2);
	}
	while (el)
	{
		print_type(el->st.st_mode);
//		print_permission(el->st.st_mode);
		print_links_nbr(el->st.st_nlink);
		print_uname(el->st.st_uid);
		print_gname(el->st.st_gid);
		ft_print_size(el->st.st_size);
		print_date(el->st.st_mtimespec.tv_sec);
		write(1, el->name, ft_strlen(el->name));
		write(1, "\n", 1);
		el = el->next;
	}
}

static void	ft_ls(char *dir_name, t_e *el)
{
	DIR				*dir_fd;
	char			s_tmp[PATH_MAX];
	struct dirent	*dirp;
	struct stat		st;

	if (!(dir_fd = opendir(dir_name)))
	{
		write(1, "ft_ls:", 7);
        perror(dir_name);
        return ;
    }
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
		add_to_list(&el, st, dirp->d_name, s_tmp);
	}
	ft_print(dir_name, el);
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
	if (argc > 1)
		ft_ls(argv[1], NULL);
	else
		printf("no arguments\n");//test
	return (0);
}
