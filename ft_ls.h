/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 10:45:03 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/17 15:26:43 by vrybchyc         ###   ########.fr       */
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

typedef	struct		s_e
{
	char			*name;
	char			*path;
	struct stat		st;
	struct s_e		*next;
}					t_e;

void		add_to_list(t_e **el, struct stat st, char *name, char *path);

#endif
