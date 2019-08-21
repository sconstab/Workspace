/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:10:48 by sconstab          #+#    #+#             */
/*   Updated: 2019/08/20 11:15:40 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ps_lstpush(t_node **alst, t_node *new)
{
	if (!(*alst) || !new)
		return ;
	(*alst)->prev = new;
	new->next = *alst;
	*alst = (*alst)->prev;
}
