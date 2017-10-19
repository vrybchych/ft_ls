/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:47:05 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/19 13:13:52 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print(char *dir_name, t_e *el)
{
	if (ft_strcmp(".", dir_name))
	{
		ft_putchar('\n');
		ft_putstr(dir_name);
		ft_putstr(":\n");
	}
	while (el)
	{
		ft_putstr(el->name);
		ft_putchar('\n');
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
        perror("Can't open");
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
