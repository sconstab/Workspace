#include "./includes/libft.h"

int		wordMatch(char *s1, char *s2)
{
	int i;
	int len1;
	int len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return(2);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return(1);
		i++;
	}
	return (0);
}