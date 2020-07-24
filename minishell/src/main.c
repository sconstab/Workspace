#include "../includes/minishell.h"

t_env		*init(void)
{
	extern char **c;
	t_env		*env;
	int i;

	i = 0;
	env = NULL;
	while (c[i] != NULL)
	{
		env = node(c[i], env);
		i++;
	}
	return (env);
}

int		main()
{
	t_env	*env;

	env = init();
	minishell(env);
	return (0);
}