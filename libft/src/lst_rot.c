/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 10:20:40 by marvin            #+#    #+#             */
/*   Updated: 2019/10/07 13:09:49 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ps_rot(t_node **alst)
{
	t_node	*tmp_lst;

	*alst = (*alst)->next;
	tmp_lst = (*alst)->prev;
	(*alst)->prev = NULL;
	while ((*alst)->next->next != NULL)
		*alst = (*alst)->next;
	tmp_lst->prev = *alst;
	tmp_lst->next = (*alst)->next;
	(*alst)->next = tmp_lst;
	tmp_lst->next->prev = tmp_lst;
	while ((*alst)->prev != NULL)
		*alst = (*alst)->prev;
}
