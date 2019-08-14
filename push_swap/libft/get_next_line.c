/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:30:06 by sconstab          #+#    #+#             */
/*   Updated: 2019/07/22 09:58:53 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	readline(int fd, char **store)
{
	char	buffer[BUFF_SIZE + 1];
	size_t	rd_index;
	char	*temp;

	if (ft_strchr(*store, '\n'))
		return (2);
	while ((rd_index = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd_index] = '\0';
		temp = ft_strjoin(*store, buffer);
		free(*store);
		*store = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rd_index);
}

int			get_next_line(int fd, char **line)
{
	static char	*stored[1024];
	char		*newline_location;
	int			rst;

	rst = 1;
	if (fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	if (stored[fd] == NULL)
		stored[fd] = ft_strnew(0);
	rst = readline(fd, &stored[fd]);
	if (rst <= 0 && !stored[fd][0])
		return (rst);
	if ((newline_location = ft_strchr(stored[fd], '\n')) == NULL && rst == 0)
		*line = stored[fd];
	if (newline_location)
	{
		*line = ft_strsub(stored[fd], 0, newline_location - stored[fd]);
		free(stored[fd]);
		stored[fd] = ft_strdup(newline_location + 1);
	}
	if (!newline_location)
		*line = stored[fd];
	if (!newline_location)
		stored[fd] = ft_strnew(0);
	return (1);
}
