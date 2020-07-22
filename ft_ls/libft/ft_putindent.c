#include "./includes/libft.h"

void	ft_putindent(int indent)
{
	int i;

	i = 0;
	while(i < indent)
	{
		ft_putchar(' ');
		i++;
	}
}