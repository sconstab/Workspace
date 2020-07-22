/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayla <ayla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:37:46 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/17 12:40:46 by ayla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_node	*ps_lstnew(void const *content, size_t content_size)
{
	t_node	*lst;

	if (!(lst = malloc(sizeof(t_node) * content_size + 1)))
		return (NULL);
	if (!(lst->dt = malloc(sizeof(t_node) * content_size + 1)))
		return (NULL);
	if (content == NULL)
	{
		lst->dt->content = NULL;
		lst->dt->content_size = 0;
	}
	else
	{
		if (!(lst->dt->content = ft_memalloc(content_size)))
		{
			free(lst);
			return (NULL);
		}
		lst->dt->content = ft_memcpy(lst->dt->content, content, content_size);
		lst->dt->content_size = content_size;
	}
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}
