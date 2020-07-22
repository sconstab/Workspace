/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayla <ayla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:16:32 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/17 12:40:46 by ayla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_node	*ps_pop(t_node **alst)
{
	t_node	*node_pop;
	t_node	*node_prev;

	if (!(*alst) || !(*alst)->next)
		return (NULL);
	*alst = (*alst)->next;
	node_pop = (*alst)->prev;
	if (node_pop->prev != NULL)
	{
		node_prev = node_pop->prev;
		node_pop->prev = NULL;
		node_prev->next = *alst;
		(*alst)->prev = node_prev;
	}
	else
		(*alst)->prev = NULL;
	node_pop->next = NULL;
	while ((*alst)->prev != NULL)
		*alst = (*alst)->prev;
	return (node_pop);
}
