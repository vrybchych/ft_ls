/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:34:43 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/06 14:57:28 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_size_s(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	fresh = (char*)malloc(sizeof(char) * (ft_size_s(s1) + ft_size_s(s2)) + 1);
	if (fresh == NULL)
		return (NULL);
	while (s1[i])
	{
		fresh[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		fresh[i] = s2[j];
		i++;
		j++;
	}
	fresh[i] = '\0';
	return (fresh);
}
