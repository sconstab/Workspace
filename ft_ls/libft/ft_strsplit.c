/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmathews <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:41:05 by zmathews          #+#    #+#             */
/*   Updated: 2019/06/29 13:06:43 by zmathews         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		ai;
	char	**sa;

	i = 0;
	ai = 0;
	if (!s || !(sa = (char **)malloc(sizeof(char *) * (ft_wc(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > k)
		{
			sa[ai] = ft_strsub(s, k, i - k);
			ai++;
		}
	}
	sa[ai] = NULL;
	return (sa);
}
