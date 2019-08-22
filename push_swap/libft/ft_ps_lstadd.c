/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:59:03 by sconstab          #+#    #+#             */
/*   Updated: 2019/08/20 11:09:38 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ps_lstadd(t_node **alst, t_node *new)
{
	t_node	*prev;

	if (!(*alst) || !new)
		return ;
	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	if ((*alst)->prev != NULL)
	{
		prev = (*alst)->prev;
		prev->next = new;
		new->prev = prev;
	}
	new->next = *alst;
	(*alst)->prev = new;
	while ((*alst)->prev != NULL)
		*alst = (*alst)->prev;
}
