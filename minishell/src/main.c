#include "../includes/minishell.h"

t_env		*init(void)
{
	extern char **ch;
	t_env		*env;
	int i;

	i = 0;
	env = NULL;
	while (ch[i] != NULL)
	{
		env = node(ch[i], env);
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