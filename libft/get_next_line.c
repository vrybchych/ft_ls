/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:58:41 by vrybchyc          #+#    #+#             */
/*   Updated: 2017/08/24 16:32:40 by vrybchyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_cut_s(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (s + (i + 1));
		i++;
	}
	free(s);
	return (NULL);
}

static char		*ft_cp_s(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	s[i] = '\0';
	return (s);
}

static int		check_n(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

static int		ft_25(const int fd, char **line, char *buf)
{
	static char	*s;
	int			ret;

	ret = BUFF_SIZE;
	if (s)
		*line = ft_cp_s(ft_strdup(s));
	while (!check_n(s) && ret == BUFF_SIZE)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		s = (!s) ? (ft_strdup(buf)) : (ft_strjoin(s, buf));
		*line = ft_cp_s(ft_strdup(s));
	}
	*line = ft_cp_s(ft_strdup(s));
	s = ft_cut_s(s);
	if (*line[0] == '\0' && ret < BUFF_SIZE)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			res;
	char		*buf;

	res = 0;
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (read(fd, buf, 0) == -1)
		return (-1);
	res = ft_25(fd, &*line, buf);
	if (buf)
		free(buf);
	return (res);
}
