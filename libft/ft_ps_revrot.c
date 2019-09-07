/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_revrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 10:36:17 by marvin            #+#    #+#             */
/*   Updated: 2019/08/21 10:36:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ps_revrot(t_node **alst)
{
	t_node	*tmp_lst;

	while ((*alst)->next->next != NULL)
		*alst = (*alst)->next;
	tmp_lst = ps_pop(alst);
	ps_lstpush(alst, tmp_lst);
}
