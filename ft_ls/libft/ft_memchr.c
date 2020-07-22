/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:15:42 by zmathews          #+#    #+#             */
/*   Updated: 2019/06/21 12:05:12 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	nc;
	size_t			i;

	s2 = (unsigned char *)s;
	nc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s2[i] == nc)
			return ((char *)&s2[i]);
		i++;
	}
	return (NULL);
}
