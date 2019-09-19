/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayla <ayla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:25:38 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/17 12:40:46 by ayla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ps_swap(t_node	**alst)
{
	t_node	*node_prev;

	if (!(*alst) || !(*alst)->next)
		return ;
	*alst = (*alst)->next;
	node_prev = (*alst)->prev;
	node_prev->prev = *alst;
	node_prev->next = (*alst)->next;
	node_prev->next->prev = node_prev;
	(*alst)->prev = NULL;
	(*alst)->next = node_prev;
}
