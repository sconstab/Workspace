/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:32 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/07 20:36:34 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			return (0);
		}
		else
			multipleFlags(data, flags, ".");
	}
	return (0);
}