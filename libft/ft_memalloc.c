/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:34:40 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/11/29 15:05:28 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*tmp;
	char	*str;
	size_t	i;

	i = 0;
	tmp = malloc(size);
	if (tmp == NULL)
		return (NULL);
	str = tmp;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (tmp);
}
