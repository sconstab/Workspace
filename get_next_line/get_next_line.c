/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayla <ayla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 06:56:45 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/19 07:37:21 by ayla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* static char		*read_file(char **line, char *lines)
{
	char	*tmp;
	int		i;

	i = 0;
	while (lines[i] != '\n' && lines[i] != '\0')
		i++;
} */
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

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*temp;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line))
		{
			temp = line;
			ft_putendl(line);
			free(temp);
		}
	}
	else
	{
		fd = open("get_next_line/get_next_line.c", O_RDONLY);
		if (fd < 1)
			return (0);
		while (get_next_line(fd, &line))
		{
			temp = line;
			ft_putendl(line);
			free(temp);
		}
	}
	close(fd);
	return (0);
}