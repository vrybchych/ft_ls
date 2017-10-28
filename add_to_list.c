/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 09:35:22 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/28 15:16:24 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_e		*create_new_elem(struct stat st, char *name, char *path)
{
	t_e				*new;

	if (!(new = (t_e*)malloc(sizeof(t_e))))
	{
		perror("NOT ENOUGH MEMORY");
		exit(0);
	}
	new->st = st;
	new->name = ft_strdup(name);
	new->path = ft_strdup(path);
	new->next = NULL;
	if (g_flag_l)
		set_width(new->st);
	return (new);
}

static int		ft_cmp(t_e *el, struct stat st, char *name)
{
	int				res;

	res = 0;
	if (g_flag_t)
		res = st.st_mtimespec.tv_sec - el->st.st_mtimespec.tv_sec;
	else
		res = ft_strcmp(el->name, name);
	return (g_flag_r ? -res : res);
}

static void		ft_norm(t_arr *a)
{
	a->prev = NULL;
	a->new = NULL;
}

void			add_to_list(t_e **el, struct stat st, char *name, char *path)
{
	t_arr			a;

	ft_norm(&a);
	a.tmp = *el;
	if (!(*el))
		*el = create_new_elem(st, name, path);
	else
	{
		while (a.tmp)
		{
			if (ft_cmp(a.tmp, st, name) > 0)
			{
				a.new = create_new_elem(st, name, path);
				a.new->next = a.tmp;
				if (a.prev)
					a.prev->next = a.new;
				if (!a.prev)
					*el = a.new;
				return ;
			}
			a.prev = a.tmp;
			a.tmp = a.tmp->next;
		}
		a.prev->next = create_new_elem(st, name, path);
	}
}
