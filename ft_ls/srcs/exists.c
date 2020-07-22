/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exists.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:32 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/07 20:36:34 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	exists(char *flag, t_ls *data, set *flags)
{
	t_ls		*head;
	struct stat	permissions;

	head = data;
	while (data->next)
	{
		if (wordMatch(flag, data->fileName) == 0)
		{
			lstat(flag, &permissions);
			if (S_ISDIR(permissions.st_mode))
				exists_3(flag, data, flags);
			if (flags->dash_l)
				exists_2(flag, data);
			else
				ft_putendl(flag);
			return;
		}
		data = data->next;
	}
	invalidFileOrDir(flag);
}

void	exists_1(char *flag, t_ls *data)
{
	while (data->next && wordMatch(data->fileName, flag) != 0)
		data = data->next;
	if (wordMatch(data->fileName, flag) == 0)
	{
		ft_putstr(flag);
		ft_putchar('/');
		ft_putchar('\n');
		data = dataTypeName(flag);
		sortAscii(data);
		printBase(data);
		exit(1);
	}
	else
		invalidFileOrDir(flag);
}

void	exists_2(char *flag, t_ls *data)
{
	while (data->next && wordMatch(data->fileName, flag) != 0)
		data = data->next;
	if (wordMatch(data->fileName, flag) == 0)
	{
		userData(data->fileName);
		ft_putchar(' ');
		ft_putstr(data->fileName);
		ft_putchar('\n');
		exit(1);
	}
	else
		invalidFileOrDir(flag);
}

void	exists_3(char *flag, t_ls *data, is_set *flags)
{
	while (data->next && wordMatch(data->fileName, flag) != 0)
		data = data->next;
	if (wordMatch(data->fileName, flag) == 0)
	{
		multipleFlags(data, flags, flag);
		exit(1);
	}
	else
		invalidFileOrDir(flag);
}