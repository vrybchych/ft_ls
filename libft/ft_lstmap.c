/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:10:41 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/06 13:22:51 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_list_begin;
	t_list		*new_list;
	t_list		*tmp;

	if (!lst)
		return (NULL);
	new_list_begin = ft_lstnew(lst->content, lst->content_size);
	new_list_begin = f(lst);
	lst = lst->next;
	new_list = ft_lstnew(lst->content, lst->content_size);
	new_list = f(lst);
	new_list_begin->next = new_list;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		tmp = f(lst);
		new_list->next = tmp;
		new_list = tmp;
		lst = lst->next;
	}
	return (new_list_begin);
}
