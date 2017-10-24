/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:21:47 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/24 13:42:59 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//ADD total!!!!!

static void		print_part2(t_e *el)
{
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(el->st.st_uid);
	gr = getgrgid(el->st.st_gid);
	print_str_width(pw->pw_name, g_uname_w);
    write(1, pw->pw_name, ft_strlen(pw->pw_name));
    write(1, " ", 1);
	print_str_width(gr->gr_name, g_gname_w);
    write(1, gr->gr_name, ft_strlen(gr->gr_name));
    write(1, " ", 1);
	print_nb_width(el->st.st_size, g_size_w);
    ft_putnbr(el->st.st_size);
    write(1, " ", 1);
	write(1, ctime(&(el->st.st_mtimespec.tv_sec)) + 4, 12);
    write(1, " ", 1);
}

static void		print_part1(mode_t m, nlink_t n)
{
	S_ISREG(m) ? write(1, "-", 1) : 0;
	S_ISDIR(m) ? write(1, "d", 1) : 0;
	S_ISCHR(m) ? write(1, "c", 1) : 0;
	S_ISBLK(m) ? write(1, "b", 1) : 0;
	S_ISLNK(m) ? write(1, "l", 1) : 0;
	S_ISSOCK(m) ? write(1, "s", 1) : 0;
	S_ISFIFO(m) ? write(1, "p", 1) : 0;
	write(1, (m & S_IRUSR) ? "r" : "-", 1);
	write(1, (m & S_IWUSR) ? "w" : "-", 1);
	write(1, (m & S_IXUSR) ? "x" : "-", 1);
	write(1, (m & S_IRGRP) ? "r" : "-", 1);
	write(1, (m & S_IWGRP) ? "w" : "-", 1);
	write(1, (m & S_IXGRP) ? "x" : "-", 1);
	write(1, (m & S_IROTH) ? "r" : "-", 1);
	write(1, (m & S_IWOTH) ? "w" : "-", 1);
	write(1, (m & S_IXOTH) ? "x" : "-", 1);
	write(1, " ", 1);
	print_nb_width(n, g_link_w);
	ft_putnbr(n);
	write(1, " ", 1);
}

void		print_l(t_e *el)
{
	print_part1(el->st.st_mode, el->st.st_nlink);
	print_part2(el);
}
