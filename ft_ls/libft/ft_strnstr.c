/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 06:35:08 by zmathews          #+#    #+#             */
/*   Updated: 2019/06/12 10:05:38 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		h;
	int		n;

	h = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[h] != '\0' && (size_t)h < len)
	{
		n = 0;
		while (needle[n] == haystack[h + n]
				&& haystack[h + n] != '\0'
				&& needle[n] != '\0')
		{
			if ((size_t)h + n > len)
				return (NULL);
			if (needle[n + 1] == '\0')
				return ((char *)haystack + h);
			n++;
		}
		h++;
	}
	return (NULL);
}
