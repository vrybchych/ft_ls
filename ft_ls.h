/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:45:03 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/25 14:21:50 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //test?
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <limits.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>

int					g_link_w;
int					g_uname_w;
int					g_gname_w;
int					g_size_w;
int					g_flag_R;
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

void		add_to_list(t_e **el, struct stat st, char *name, char *path);
void		print_l(t_e *el);
void		set_width(struct stat st);
void		print_nb_width(int nb, int width);
void		print_str_width(char *str, int width);
void		sort_and_check_argv(char **argv, int i, int argc);
void		ft_ls(char *dir_name, t_e *el);

#endif
