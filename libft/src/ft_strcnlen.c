/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayla <ayla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:29:49 by sconstab          #+#    #+#             */
/*   Updated: 2019/09/17 12:40:46 by ayla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strcnlen(char const *s, char c, size_t x)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	n = 0;
	if (s[i] != c)
		j++;
	while (s[i] && j <= x)
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			j++;
		}
		else
			while (s[i] != c && s[i])
				i++;
	}
	while (s[i++] != c && s[i])
		n++;
	return (n);
}
