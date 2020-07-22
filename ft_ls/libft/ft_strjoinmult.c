#include "./includes/libft.h"

char	*ft_strjoinmult(char *s1, char *s2, char *s3)
{
	char *tmp;
	char *j;

	tmp = ft_strjoin(s1, s3);
	j = strdup(tmp);
	free(tmp);
	tmp = ft_strjoin(j, s2);
//	s1 = ft_strjoin(s1, s3);
	free(j);
	return (tmp);
//	return(ft_strjoin(s1, s2));
}