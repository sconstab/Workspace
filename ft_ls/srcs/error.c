#include "../includes/ft_ls.h"

void	invalidFileOrDir(char *flagString)
{
	ft_putstr("ft_ls: ");
	ft_putstr(flagString);
	ft_putendl(": No such file or directory");
	exit(1);
}

void	illegalOption(char flag)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
	exit(1);
}