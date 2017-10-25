/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_check_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <vrybchyc@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:35:01 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/10/25 15:03:18 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

typedef struct		s_lst
{
	char 			*s;
	struct s_lst	*next;
}					t_lst;

static t_lst	*create_new_lst(char *s)
{
	t_lst	*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	new->s = ft_strdup(s);
	new->next = NULL;
	return (new);
}

static		void list_add(t_lst **l, char *s)
{
	t_lst		*new;
	t_lst		*prev;
	t_lst		*tmp;

	prev = NULL;
	new = NULL;
	tmp = *l;
	if (!(*l))
		*l = create_new_lst(s);
	else
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->s, s) > 0)
			{
				new = create_new_lst(s);
				new->next = tmp;
				if (prev)
					prev->next = new;
				else
					*l = new;
				return ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = create_new_lst(s);;
	}
}

static	void		check_errors(t_lst **l)
{
	t_lst 		*begin;
	t_lst		*prev;
	t_lst		*tmp;
	DIR         *dir_fd;

	begin = *l;
	prev = NULL;
	while (begin)
	{
		if (!(dir_fd = opendir(begin->s)))
		{
			write(1, "ft_ls: ", 8);
			perror(begin->s);
			if (prev)
				prev->next = begin->next;
			tmp = begin;
			begin = begin->next;
			free(tmp->s);
			free(tmp);
		}
		else
		{
			closedir(dir_fd);
			prev = begin;
			begin = begin->next;
		}
	}
}


void		sort_and_check_argv(char **argv, int i, int argc)
{
	t_lst		*l;
	t_lst		*begin;

	l = NULL;
	while (i < argc)
		list_add(&l, argv[i++]);
	check_errors(&l);
	begin = l;
	write(1, l->s, ft_strlen(l->s));
	write(1, ":\n", 2);
	while (l)
	{
		ft_ls(l->s, NULL);
		l = l->next;
	}
	while (begin)
	{
		free(begin->s);
		free(begin);
		begin = begin->next;
	}
}
