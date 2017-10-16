/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:44:06 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/11/29 18:26:03 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	size;
	unsigned int	i;

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
		fresh[i] = f(i, s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
