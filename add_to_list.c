/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 09:35:22 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/27 19:30:08 by vrybchyc         ###   ########.fr       */
/*                                                                            */

/* ************************************************************************** */

#include "ft_ls.h"

static t_e	*create_new_elem(struct stat st, char *name, char *path)
{
	t_e		*new;

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

static int	ft_cmp(t_e *el, struct stat st, char *name)
{
//	g_flag_f
	int		res;

	res = 0;
	if (g_flag_t)
		res = st.st_mtimespec.tv_sec - el->st.st_mtimespec.tv_sec;
	else
		res = ft_strcmp(el->name, name);
	return (g_flag_r ? -res : res);
}


void		add_to_list(t_e **el, struct stat st, char *name, char *path)
{
	t_e		*tmp;
	t_e		*prev = NULL;
	t_e		*new = NULL;

	tmp = *el;
	if (!(*el))
		*el = create_new_elem(st, name, path);
	else
	{		
		while (tmp)
		{
			if (ft_cmp(tmp, st, name) > 0)
			{
				new = create_new_elem(st, name, path);
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
		prev->next = create_new_elem(st, name, path);
	}
}
