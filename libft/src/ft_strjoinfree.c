/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:54:05 by sconstab          #+#    #+#             */
/*   Updated: 2019/10/07 13:26:43 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	size_t	i;
	char	*s;

	i = 0;
	if (!(s = malloc(sizeof(s) * (ft_strlen(s1) + ft_strlen(s2) + 1))) || !s1)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		s[i] = *s2;
		s2++;
		i++;
	}
	s[i] = '\0';
	free(s1);
	return (s);
}
