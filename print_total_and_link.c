/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total_and_link.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:58:08 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/28 15:23:36 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_link(t_e *el)
{
	char		buf[PATH_MAX + 1];
	size_t		ret;

	ret = readlink(el->path, buf, PATH_MAX);
	buf[ret] = '\0';
	write(1, " -> ", 4);
	write(1, buf, ft_strlen(buf));
}

void		print_total(t_e *el)
{
	int			total;

	total = 0;
	while (el)
	{
		total += el->st.st_blocks;
		el = el->next;
	}
	write(1, "total ", 6);
	ft_putnbr(total);
	write(1, "\n", 1);
}
