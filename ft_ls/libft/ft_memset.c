/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:05:16 by zmathews          #+#    #+#             */
/*   Updated: 2019/05/27 07:48:34 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*alt;
	unsigned char	replace;
	size_t			count;

	alt = (char *)b;
	replace = c;
	count = 0;
	while (count < len)
	{
		alt[count] = replace;
		count++;
	}
	return (b);
}
