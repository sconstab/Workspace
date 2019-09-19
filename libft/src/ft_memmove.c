/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayla <ayla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:56:27 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/17 12:40:46 by ayla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	char	*lsrc;
	char	*ldst;

	if (src == NULL && dst == NULL)
		return (NULL);
	csrc = (char *)src;
	cdst = (char *)dst;
	if (cdst < csrc)
		while (len--)
			*cdst++ = *csrc++;
	else
	{
		lsrc = csrc + (len - 1);
		ldst = cdst + (len - 1);
		while (len--)
			*ldst-- = *lsrc--;
	}
	return (dst);
}
