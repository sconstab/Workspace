/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 06:56:45 by sconstab          #+#    #+#             */
/*   Updated: 2019/10/07 12:53:44 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*read_file(char **line, char *lines)
{
	char	*tmp;
	int		i;

	i = 0;
	while (lines[i] != '\n' && lines[i] != '\0')
		i++;
	*line = ft_strsub(lines, 0, i);
	if (ft_strcmp(lines, *line) == 0)
		return (NULL);
	else
	{
		tmp = ft_strsub(lines, i + 1, ft_strlen(lines + i) + 1);
		free(lines);
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int			val;
	char		tmp[BUFF_SIZE + 1];
	static char	*store[1024];

	val = 0;
	if (read(fd, tmp, 0) < 0 || fd < 0 || line == NULL)
		return (-1);
	if (!store[fd])
		store[fd] = ft_strnew(0);
	if (!(ft_strchr(store[fd], '\n')))
	{
		while ((val = read(fd, tmp, BUFF_SIZE)) > 0)
		{
			tmp[val] = '\0';
			store[fd] = ft_strjoinfree(store[fd], tmp);
			if (ft_strchr(store[fd], '\n'))
				break ;
		}
	}
	if (val == 0 && !(ft_strlen(store[fd])))
		return (0);
	store[fd] = read_file(line, store[fd]);
	return (1);
}
/* 
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
} */