/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:32 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/07 20:36:34 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

set		*setFlags(void)
{
	set *flags;

	flags = (set *)malloc(sizeof(set));
	flags->a = 0;
	flags->r = 0;
	flags->t = 0;
	flags->l = 0;
	flags->R = 0;
	return (flags);
}

void	freeFlags(set *flags)
{
	free(flags);
}

void	initMain(int ac, char **av, int avi, t_ls *data, set *flags)
{
	while (avi < ac)
	{
		data = dataTypeName(".");
		exists(av[avi], data, flags);
		listDel(data);
		avi++;
	}
}

void	listDel(t_ls *data)
{
	t_ls	*node;

	while (data)
	{
		node = data;
		data = data->next;
		free(node);
	}
}