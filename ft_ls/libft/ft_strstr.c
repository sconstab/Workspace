/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:20:36 by zmathews          #+#    #+#             */
/*   Updated: 2019/06/11 17:46:05 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int h;
	int n;

	h = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[h] != '\0')
	{
		n = 0;
		while (needle[n] == haystack[h + n]
				&& haystack[h + n] != '\0'
				&& needle[n] != '\0')
		{
			if (needle[n + 1] == '\0')
				return ((char *)haystack + h);
			n++;
		}
		h++;
	}
	return (NULL);
}
