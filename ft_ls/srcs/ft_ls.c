#include "../includes/ft_ls.h"

int	main(int ac, char **av)
{
	t_ls	*data;
	set		*flags;
	int		avi;

	data = NULL;
	flags = NULL;
	avi = 1;
	if (ac == 1)
		printBasic(data);
	else if (ac > 1)
	{
		data = dataTypeName(".");
		flags = setFlags();
		flagCheck(ac, av, flags, data);
		if (findDash(av[avi], flags) == 3)
		{
			initMain(ac, av, avi, data, flags);
			system("leaks ft_ls");
			return (0);
		}
		else
			multipleFlags(data, flags, ".");
	}
	system("leaks ft_ls");
	return (0);
}