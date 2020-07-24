#include "../includes/minishell.h"

t_env		*init(void)
{
	extern char **ext_c;
	t_env		*env;
	int i;

	i = 0;
	env = NULL;
	while (ext_c[i] != NULL)
	{
		env = node(ext_c[i], env);
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