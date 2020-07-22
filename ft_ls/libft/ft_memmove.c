/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:53:41 by zmathews          #+#    #+#             */
/*   Updated: 2019/06/21 12:01:19 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	if (dst1 > src1)
	{
		i = len;
		while (i > 0)
		{
			dst1[i - 1] = src1[i - 1];
			i--;
		}
		return (dst);
	}
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
