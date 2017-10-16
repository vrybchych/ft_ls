/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:34:04 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/06 14:56:00 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_size_itoa(int nbr)
{
	int size;

	size = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		size++;
	}
	return (size);
}

static char		*ft_str_rev(char *str)
{
	int		i;
	int		length;
	char	tmp;

	i = 0;
	length = 0;
	while (str[length])
		length++;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
	return (str);
}

static char		*ft_minus_nbr(int nbr, char *str, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str[i] = '-';
	str[i + 1] = '\0';
	return (ft_str_rev(str));
}

static char		*ft_nbr(int nbr, char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str[i] = '\0';
	return (ft_str_rev(str));
}

char			*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
	{
		if ((str = (char*)malloc(sizeof(char) * 11)) == NULL)
			return (NULL);
		str = ft_minus_nbr(2147483647, str, 11);
		str[10] = '8';
		str[11] = '\0';
		return (str);
	}
	size = ft_size_itoa(n);
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		return (ft_minus_nbr(-n, str, size));
	else
		return (ft_nbr(n, str, size));
	return (0);
}
