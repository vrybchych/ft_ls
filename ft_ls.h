/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:45:03 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/19 19:04:16 by vrybchyc         ###   ########.fr       */
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

typedef	struct		s_e
{
	char			*name;
	char			*path;
	struct stat		st;
	struct s_e		*next;
}					t_e;

void		add_to_list(t_e **el, struct stat st, char *name, char *path);
void		print_gname(gid_t gid);
void		print_date(time_t t);
void		print_links_nbr(nlink_t n);
//void		print_permission(mode_t m);
void		print_type(mode_t m);
void		print_uname(uid_t uid);
void		ft_print_size(off_t size);

#endif
