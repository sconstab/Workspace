/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:16:51 by zmathews          #+#    #+#             */
/*   Updated: 2019/06/24 09:49:54 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	index;
	size_t	j;
	char	*str;

	i = 0;
	index = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[index] == ' ' || s[index] == '\t' || s[index] == '\n')
		index++;
	i = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\0' || s[i] == '\t' || s[i] == '\n')
		if (i-- == index)
		{
			str = (char *)malloc(sizeof(char) * ((i - index) + 2));
			return (str);
		}
	if (!s || !(str = (char *)malloc(sizeof(char) * ((i - index) + 2))))
		return (NULL);
	while (index < i + 1)
		str[j++] = s[index++];
	str[j] = '\0';
	return (str);
}
