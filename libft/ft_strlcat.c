/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:01:54 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/06 14:42:40 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	j = 0;
	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	i = dst_len;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	src_len = ft_strlen(src);
	if (dst_len < size)
		dst[i] = '\0';
	return (dst_len + src_len);
}
