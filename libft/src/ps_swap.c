/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:25:38 by sconstab          #+#    #+#             */
/*   Updated: 2019/10/07 13:10:06 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ps_swap(t_node **alst)
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
