/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:45:03 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/28 15:39:42 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <limits.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>

int					g_link_w;
int					g_uname_w;
int					g_gname_w;
int					g_size_w;
int					g_minor_w;
int					g_flag_br;
int					g_flag_t;
int					g_flag_a;
int					g_flag_l;
int					g_flag_r;

typedef	struct		s_e
{
	char			*name;
	char			*path;
	struct stat		st;
	struct s_e		*next;
}					t_e;

typedef struct		s_arr
{
	t_e				*tmp;
	t_e				*prev;
	t_e				*new;
}					t_arr;

typedef struct		s_lst
{
	char			*s;
	struct s_lst	*next;
}					t_lst;

void				add_to_list(t_e **el, struct stat st,
							char *name, char *path);
void				print_l(t_e *el);
void				set_width(struct stat st);
void				print_nb_width(int nb, int width);
void				print_str_width(char *str, int width);
void				sort_and_check_argv(char **argv, int i, int argc);
void				ft_ls(char *dir_name, t_e *el);
void				free_el(t_e *el);
void				print_total(t_e *el);
void				print_link(t_e *el);

#endif
