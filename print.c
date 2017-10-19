/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:21:47 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/19 19:15:39 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_date(time_t t)
{
	// if more then 6 month
	write(1, ctime(&t) + 4, 12);
	write(1, " ", 1);
}


void		print_type(mode_t m)
{
	if (S_ISREG(m))
		write(1, "-", 1);
	else if (S_ISDIR(m))
		write(1, "d", 1);
	else if (S_ISCHR(m))
		write(1, "c", 1);
	else if (S_ISBLK(m))
		write(1, "b", 1);
	else if (S_ISLNK(m))
		write(1, "l", 1);
	else if (S_ISSOCK (m))
		write(1, "s", 1);
	else if (S_ISFIFO(m))
		write(1, "p", 1);
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
}

void		print_links_nbr(nlink_t n)
{
	//add presision

	ft_putnbr(n);
	write(1, " ", 1);
}

void		print_uname(uid_t uid)
{
	//add presision

	struct passwd *pw;

	pw = getpwuid(uid);
	write(1, pw->pw_name, ft_strlen(pw->pw_name));
	write(1, " ", 1);
}

void		print_gname(gid_t gid)
{
	//add presision

	struct group *gr;

	gr = getgrgid(gid);
	write(1, gr->gr_name, ft_strlen(gr->gr_name));
    write(1, " ", 1);
}

void		ft_print_size(off_t size)
{
	//add presision

    ft_putnbr(size);
    write(1, " ", 1);

}
