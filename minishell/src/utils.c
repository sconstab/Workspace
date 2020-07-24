#include "../includes/minishell.h"

int		check_for_env(t_enviro *env, char *to_find)
{
	t_enviro *head;

	head = env;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, to_find) == 0)
			return (1);
		head = head->next;
	}
	return (0);
}

char		*get_env_value(t_enviro *env, char *to_get)
{
	t_enviro *head;

	head = env;
	while (head != NULL)
	{
		if (ft_strcmp(head->key, to_get) == 0)
			break;
		head = head->next;
	}
	return (ft_strdup(head->value));
}

int		change_directory(char *path, char *message)
{
	int flag;
	
	flag = chdir(path);
	if (flag != 0)
	{
		ft_putstr(path);
		ft_putendl(message);
		return (0);
	}
	return (1);
}

void		move_to_oldpwd(t_enviro *env)
{
	char *curr;
	char *full_var;
	char curr_dir[1024];

	bzero(curr_dir, 1024);
	getcwd(curr_dir, 1024);
	curr = get_env_value(env, "PWD");
	full_var = create_env("OLDPWD", curr);
	ft_setenv(env, full_var);
	free(full_var);
	full_var = create_env("PWD", curr_dir);
	ft_setenv(env, full_var);
	free(curr);
	free(full_var);
}

char	*create_env(char *key, char *value)
{
	char *tmp;
	char *env;

	tmp = ft_strjoin(key, "=");
	env = ft_strjoin(tmp, value);
	free(tmp);
	return (env);
}