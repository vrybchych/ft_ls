/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:27:34 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/11/30 19:01:47 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	i;

	if (!s1)
		return (0);
	i = 0;
	fresh = (char*)malloc(sizeof(char) * len + 1);
	if (fresh == NULL)
		return (NULL);
	while ((size_t)i < len && s1[start])
	{
		fresh[i] = s1[start];
		start++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
