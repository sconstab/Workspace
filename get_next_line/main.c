#include "get_next_line.h"

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
