/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 20:22:36 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/11/30 18:58:27 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] && (size_t)i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while ((size_t)i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
