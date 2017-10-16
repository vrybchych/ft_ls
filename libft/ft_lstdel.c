/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:55:52 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/02 18:52:48 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp1;

	while (*alst)
	{
		tmp1 = *alst;
		tmp = tmp1->next;
		del(tmp1->content, tmp1->content_size);
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
}
