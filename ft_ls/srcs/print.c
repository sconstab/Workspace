/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:32 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/07 20:36:34 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	printAll(t_ls *lst)
{
	while (lst->next != NULL)
	{
		ft_putendl(lst->fileName);
		lst = lst->next;
	}
	return;
}

void	printBase(t_ls *a)
{
	t_ls *lst;

	lst = a;
	while (lst->next != NULL)
	{
		if (lst->fileName[0] == '.')
		{
			lst = lst->next;
			continue;
		}
		ft_putendl(lst->fileName);
		lst = lst->next;
	}
}

void	printNString(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	dash_R(char *str, int indent)
{
	DIR *dir;
	struct dirent *store;
	char *path;
	char *tmp;

	if (!(dir = opendir(str)))
		return;
	while ((store = readdir(dir)) != NULL)
	{
		if (store->d_type == DT_DIR)
		{
			if (store->d_name[0] == '.')
				continue;
			path = ft_strjoinmult(str, store->d_name, "/");
			ft_putindent(indent);
			tmp = ft_strjoin("./", store->d_name);
			ft_putendl(tmp);
			free(tmp);
			dash_R(path, indent + 2);
			free(path);
		}
		else
		{
			ft_putindent(indent);
			ft_putendl(store->d_name);
		}
	}
	closedir(dir);
}

void	printBasic(t_ls *data)
{
	data = dataTypeName(".");
	sortAscii(data);
	printBase(data);
	listDel(data);
}

void	multipleFlags(t_ls *data, set *flags, char *flagString)
{
	if (flags->R)
		dash_R(flagString, 0);
	else if (flags->a)
	{
		data = dataTypeName(flagString);
		sortAscii(data);
		if (flags->r)
			sortRevList(data);
		if (flags->t)
			sortTime(data, flags);
		if (flags->l)
			printEverything(data, flags);
		else if (!flags->l)
			printAll(data);
	}
	else if (!flags->a)
	{
		data = dataTypeName(flagString);
		sortAscii(data);
		if (flags->r)
			sortRevList(data);
		if (flags->t)
			sortTime(data, flags);
		if (flags->l)
			printEverything(data, flags);
		else if (!flags->l)
			printBase(data);
	}
	listDel(data);
}