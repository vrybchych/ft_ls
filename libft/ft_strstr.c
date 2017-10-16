/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:34:57 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/11/30 19:00:32 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = 0;
	while (little[size])
		size++;
	if (size == 0)
		return ((char*)big);
	while (big[i])
	{
		while (little[j] == big[i + j])
		{
			if (j == size - 1)
				return ((char*)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
