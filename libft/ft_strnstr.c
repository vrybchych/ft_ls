/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:48:21 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/06 14:56:32 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int		ft_size(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char		*ft_25(const char *big, const char *lit, size_t len, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (big[i])
	{
		while (lit[j] == big[i + j])
		{
			if ((size_t)count > len - 1)
				return (0);
			if (j == ft_size(lit) - 1)
				return ((char*)big + i);
			j++;
			count++;
		}
		count++;
		j = 0;
		i++;
	}
	return (0);
}

char			*ft_strnstr(const char *big, const char *lit, size_t len)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	if (ft_size(lit) == 0)
		return ((char*)big);
	return (ft_25(big, lit, len, 0));
}
