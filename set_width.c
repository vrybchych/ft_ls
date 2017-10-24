/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 13:39:08 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/23 14:26:00 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** nw - number width
** sw - str width
*/

static int	nw(int nb)
{
	int		width;

	width = 1;
	while (nb /= 10)
		width++;
	return (width);
}

static int	sw(char *s)
{
	int		width;

	width = -1;
	while (s[++width]);
	return (width);
}

void		set_width(struct stat st)
{
	struct passwd *pw;
	struct group *gr;

	pw = getpwuid(st.st_uid);
	gr = getgrgid(st.st_gid);
	g_link_w = nw(st.st_nlink) > g_link_w ? nw(st.st_nlink) : g_link_w;
	g_uname_w = sw(pw->pw_name) > g_uname_w ? sw(pw->pw_name) : g_uname_w;
	g_gname_w = sw(gr->gr_name) > g_gname_w ? sw(gr->gr_name) : g_gname_w;
	g_size_w = nw(st.st_size) > g_size_w ? nw(st.st_size) : g_size_w;
}

void		print_nb_width(int nb, int width)
{
	int 	current_width;

	current_width = nw(nb);
	while (width > current_width++)
		write(1, " ", 1);
}

void		print_str_width(char *str, int width)
{
	int    current_width;

    current_width = sw(str);
    while (width > current_width++)
		write(1, " ", 1);
}
