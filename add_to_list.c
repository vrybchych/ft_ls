/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 09:35:22 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/16 15:22:39 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
static int	n_count(char *s)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i])
		if (s[i++] == '/')
			n++;
	return (n);
}

static int	ft_cmp(char *s1, char *s2)
{
	if (n_count(s1) != n_count(s2) != 0)
		return (n_count(s1) - n_count(s2));
	return (ft_strcmp(s1, s2));
}
*/
static t_e	*create_new_elem(struct stat st, char *name)
{
	t_e		*new;

	if (!(new = (t_e*)malloc(sizeof(t_e))))
	{
		perror("NOT ENOUGH MEMORY");
		exit(0);
	}
	new->st = st;
	new->name = ft_strdup(name);
	new->next = NULL;
	return (new);
}

void		add_to_list(t_e **el, struct stat st, char *name)
{
	t_e		*tmp;
	t_e		*prev = NULL;
	t_e		*new = NULL;

	tmp = *el;
	if (!(*el))
		*el = create_new_elem(st, name);
	else
	{		
		while (tmp)
		{
			if (ft_strcmp(tmp->name, name) > 0)
			{
				new = create_new_elem(st, name);
				new->next = tmp;
				if (prev)
					prev->next = new;
				if (!prev)
					*el = new;
				return ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = create_new_elem(st, name);
	}
}
