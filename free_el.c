/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_el.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:01:01 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/27 14:03:52 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_el(t_e *el)
{
	t_e		*tmp;

	while (el)
	{
		free(el->name);
		free(el->path);
		tmp = el;
		el = el->next;
		free(tmp);
	}
}
