/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:32 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/07 20:36:34 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		doubleDash(int ac, char *flag)
{
	int	l;

	l = ft_strlen(flag);
	if (ac >= 2 && flag[0] == '-' && flag[1] == '-' && l > 2)
		return (1);
	else if (ac >= 2 && flag[0] == '-' && flag[1] == '-' && l == 2)
		return (2);
	else
		return (0);
}

int		findDash(char *flag, set *flags)
{
	int	foundFlags;
	int	foundOther;

	foundFlags = 0;
	foundOther = 0;
	if (flag[0] != '-')
	{
		foundOther += 1;
		flags->foundOther = 1;
		return (3);
	}
	return (0);
}

void	flagCheck(int ac, char **av, set *flags, t_ls *data)
{
	int	avi;

	avi = 1;
	while (avi < ac)
	{
		if (doubleDash(ac, av[avi]) == 2)
		{
			printBasic(data);
			exit(1);
		}
		if (doubleDash(ac, av[avi]) == 1)
		{
			illegalOption(av[avi][1]);
			exit(1);
		}
		flagCheck1(av, avi, flags, data);
		avi++;
	}
}

void	flagCheck1(char **av, int avi, set *flags, t_ls *data)
{
	int	i;

	i = 1;
	if (av[avi][0] == '-')
	{
		if (ft_strlen(av[avi]) == 1)
			invalidFOrD("-");
		while (av[avi][i])
		{
			if (!ft_strchr("larRt", av[avi][i]))
			{
				illegalOption(av[avi][i]);
				exit(1);
			}
			i++;
		}
		if (ft_strchr(av[avi], 'a'))
			flags->a = 1;
		if (ft_strchr(av[avi], 'r'))
			flags->r = 1;
		if (ft_strchr(av[avi], 't'))
			flags->t = 1;
		if (ft_strchr(av[avi], 'l'))
			flags->l = 1;
		if (ft_strchr(av[avi], 'R'))
			flags->R = 1;
	}
	else if (av[avi][0] != '-')
	{
		exists(av[avi], data, flags);
		exit(1);
	}
}