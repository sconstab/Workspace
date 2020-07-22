/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:33:32 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/07 20:36:34 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	sortAscii(t_ls *tmp)
{
	t_ls	*head;
	char	*str;

	head = tmp;
	while (tmp->next != NULL)
	{
		if (tmp->fileName == NULL)
			tmp = tmp->next;
		if (ft_strcmp(tmp->fileName, tmp->next->fileName) > 0)
		{
			str = tmp->fileName;
			tmp->fileName = tmp->next->fileName;
			tmp->next->fileName = str;
			tmp = head;
		}
		else
			tmp = tmp->next;
	}
	tmp->next = NULL;
	tmp = head;
}

void	sortRevList(t_ls *tmp)
{
	t_ls	*head;
	char	*str;

	head = tmp;
	while (tmp->next->fileName != NULL)
	{
		if (tmp->fileName == NULL)
			tmp = tmp->next;
		if (ft_strcmp(tmp->fileName, tmp->next->fileName) < 0)
		{
			str = tmp->fileName;
			tmp->fileName = tmp->next->fileName;
			tmp->next->fileName = str;
			tmp = head;
		}
		else
			tmp = tmp->next;
	}
	tmp = head;
}

int		timeCompare(char *s1, char *s2)
{
	struct stat	time1;
	struct stat	time2;

	stat(s1, &time1);
	stat(s2, &time2);
	if (time1.st_ctime == time2.st_ctime)
		return (time1.st_ctimespec.tv_nsec < time2.st_ctimespec.tv_nsec);
	return (time1.st_ctime < time2.st_ctime);
}

void	sortTime(t_ls *tmp, is_set *flags)
{
	t_ls	*head;
	char	*str;

	head = tmp;
	while (tmp->next != NULL)
	{
		if (flags->dash_r)
		{
			if (timeCompare(tmp->next->fileName, tmp->fileName))
			{
				str = tmp->next->fileName;
				tmp->next->fileName = tmp->fileName;
				tmp->fileName = str;
				tmp = head;
			}
			else
				tmp = tmp->next;
		}
		else
		{
			if (timeCompare(tmp->fileName, tmp->next->fileName))
			{
				str = tmp->fileName;
				tmp->fileName = tmp->next->fileName;
				tmp->next->fileName = str;
				tmp = head;
			}
			else
				tmp = tmp->next;
		}
	}
	tmp->next = NULL;
	tmp = head;
}