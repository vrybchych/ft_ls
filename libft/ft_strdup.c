/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:40:06 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/11/28 19:53:27 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	int		size;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	s2 = (char*)malloc(sizeof(char) * size + 1);
	if (s2 != NULL)
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
