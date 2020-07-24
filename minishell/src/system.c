#include "../includes/minishell.h"

void	ft_system(t_enviro *env, char *buffer)
{
	char	**segments;
	pid_t	pid;
	char	*str1;
	char	*str2;
	char	**envp;
	t_enviro *head;

	head = env;
	envp = NULL;
	segments = ft_strsplit(buffer, ' ');
	while (env != NULL)
	{
		str1 = ft_strjoin(env->key, "=");
		str2 = ft_strjoin(str1, env->value);
		free(str1);
		envp = arraypush(envp, str2);
		free(str2);
		env = env->next;
	}
	if ((pid = fork()) == 0)
	{
		if (segments[0][0] == '/')
			execve(segments[0], segments, envp);
		else
			scan_path(head, segments);
		exit(1);
	}
	else
		wait(&pid);
	free2d(envp);
	free2d(segments);
}

void	scan_path(t_enviro *env, char **segments)
{
	char *pathway;
	t_enviro *head;

	pathway = NULL;
	head = env;
	while (env != NULL)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
		{
			pathway = ft_strdup(env->value);
			break;
		}
		env = env->next;
	}
	if (pathway)
		scan_dir(pathway, segments, head);
	free(pathway);
}

void	scan_dir(char *pathway, char **segments, t_enviro *env)
{
	DIR		*dp;
	struct dirent	*dir;
	char	**values;
	int i;
	int check;

	check = 0;
	values = ft_strsplit(pathway, ':');
	if (!values)
		return ;
	i = 0;
	while (values[i])
	{
		if ((dp = opendir(values[i])) == NULL)
		{
			i++;
			continue;
		}
		while ((dir = readdir(dp)))
		{
			if (ft_strcmp(dir->d_name, "..") == 0 || ft_strcmp(dir->d_name, ".") == 0)
				continue;
			if (ft_strcmp(segments[0], dir->d_name) == 0)
			{
				execute(segments, values[i], env);
				check = 1;
				break;
			}
		}
		if (check == 1)
			break;
		closedir(dp);
		i++;
	}
	if (check == 0)
		ft_putendl("Error: Command not found");
	free2d(values);
}

void	execute(char **segment, char *cur_dir, t_enviro *env)
{
	char *str1;
	char *str2;
	char **envp;

	envp = NULL;

	while (env != NULL)
	{
		str1 = ft_strjoin(env->key, "=");
		str2 = ft_strjoin(str1, env->value);
		free(str1);
		envp = arraypush(envp, str2);
		free(str2);
		env = env->next;
	}
	str1 = ft_strjoin(cur_dir, "/");
	str2 = ft_strjoin(str1, segment[0]);
	execve(str2, segment, envp);
	free(str1);
	free(str2);
	free2d(envp);
}