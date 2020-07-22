/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 08:42:37 by zmathews          #+#    #+#             */
/*   Updated: 2019/06/12 11:12:02 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dsti;
	size_t srci;
	size_t dst_len;
	size_t src_len;

	dsti = 0;
	srci = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	while ((dst[dsti]) && (dsti < dstsize - 1))
		dsti++;
	while ((src[srci]) && (dsti < dstsize - 1))
	{
		dst[dsti] = src[srci];
		dsti++;
		srci++;
	}
	dst[dsti] = '\0';
	return (dst_len + src_len);
}
