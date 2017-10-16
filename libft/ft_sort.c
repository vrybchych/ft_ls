/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:16:59 by vrybchyc          #+#    #+#             */
/*   Updated: 2016/12/06 15:18:46 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
