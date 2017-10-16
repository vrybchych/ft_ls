/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:36:27 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/06 14:57:04 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strln_no_sp(char const *s)
{
	int begin_sp;
	int end_sp;
	int size;

	begin_sp = 0;
	end_sp = 0;
	size = 0;
	while (s[size])
		size++;
	while (s[begin_sp] == ' ' || s[begin_sp] == '\t' || s[begin_sp] == '\n')
		begin_sp++;
	while (s[size - 1] == ' ' || s[size - 1] == '\t' || s[size - 1] == '\n')
		size--;
	if (size > begin_sp)
		return (size - begin_sp);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*copy;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	copy = (char*)malloc(sizeof(char) * ft_strln_no_sp(s) + 1);
	if (copy == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] && j < ft_strln_no_sp(s))
	{
		copy[j] = s[i];
		i++;
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
