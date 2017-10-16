/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:56:49 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/02 18:52:17 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	void	*content_copy;
	size_t	i;

	i = 0;
	if ((tmp = (t_list*)malloc(content_size)) == NULL)
		return (NULL);
	if (content == NULL)
	{
		content_copy = NULL;
		tmp->next = NULL;
		tmp->content = content_copy;
		tmp->content_size = 0;
	}
	else
	{
		if ((content_copy = (t_list*)malloc(content_size)) == NULL)
			return (NULL);
		content_copy = ft_memcpy(content_copy, content, content_size);
	}
	tmp->content = content_copy;
	tmp->next = NULL;
	return (tmp);
}
