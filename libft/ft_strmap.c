/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:23:12 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/11/29 18:24:42 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;
	int		size;

	if (!s)
		return (0);
	i = 0;
	size = 0;
	while (s[size])
		size++;
	fresh = (char*)malloc(sizeof(char) * size + 1);
	if (fresh == NULL)
		return (NULL);
	while (s[i])
	{
		fresh[i] = f(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
