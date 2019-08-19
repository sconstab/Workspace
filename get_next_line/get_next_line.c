/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 06:56:45 by sconstab          #+#    #+#             */
/*   Updated: 2019/08/19 09:18:27 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_line(const int fd, char **stored)
{
	int			ret;
	char		*got;
	char		*tmp;

	if (!(got = ft_strnew(BUFF_SIZE)))
		return (-1);
	ret = read(fd, got, BUFF_SIZE);
	if (ret > 0)
	{
		got[ret] = 0;
		if (!(tmp = ft_strjoin(*stored, got)))
			return (-1);
		free(*stored);
		*stored = tmp;
		free(got);
	}
	if (ret == 0)
		free(got);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	int			val;
	static char	*store[1024];
	char		*tmp;

	if (!store[fd])
		store[fd] = ft_strnew(BUFF_SIZE);
	if (!store[fd] || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	tmp = ft_strchr(store[fd], '\n');
	while (!tmp)
	{
		val = read_line(fd, &store[fd]);
		if (val == 0 && !ft_strlen(store[fd]))
			return (0);
		if (val == 0)
			ft_strcat(store[fd], "\n");
		if (val < 0)
			return (-1);
		else
			tmp = ft_strchr(store[fd], '\n');
	}
	if (!(*line = ft_strsub(store[fd], 0, ft_strlen(store[fd]) - ft_strlen(tmp))))
		return (-1);
	ft_strcpy(store[fd], tmp + 1);
	return (1);
}
