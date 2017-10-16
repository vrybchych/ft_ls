/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:09:57 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/06 14:58:30 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_count_a(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int		ft_count_w(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i + 1);
}

static char		*ft_create_tab_i(char const *s, char c, char *str, int k)
{
	int j;

	j = 0;
	while (s[k] && s[k] != c)
	{
		str[j] = s[k];
		k++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char		**ft_create_tab(char const *s, char c, char **tab, int i)
{
	int k;

	k = 0;
	while (s[k])
	{
		while (s[k] == c && s[k])
			k++;
		if (s[k] && s[k] != c)
		{
			tab[i] = (char*)malloc(sizeof(char) * ft_count_w(&s[k], c) + 1);
			if (tab[i] == NULL)
				return (NULL);
			tab[i] = ft_create_tab_i(s, c, tab[i], k);
			while (s[k] && s[k] != c)
				k++;
			i++;
		}
	}
	tab[i] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s || !c)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * ft_count_a(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	tab = ft_create_tab(s, c, tab, 0);
	return (tab);
}
