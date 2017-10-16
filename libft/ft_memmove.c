/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:03:26 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/11/30 11:54:16 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;

	if (dst >= src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			*((char*)dst + i) = *((char*)src + i);
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < len)
		{
			*((char*)dst + i) = *((char*)src + i);
			i++;
		}
	}
	return (dst);
}
