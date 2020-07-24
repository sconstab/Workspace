#include "../includes/minishell.h"

t_enviro	*new_node(const char *stuff)
{
	t_enviro	*new;
	char		**key_value;

	key_value = split_kv(stuff);
	new = (t_enviro *)malloc(sizeof(t_enviro));
	new->key = ft_strdup(key_value[0]);
	new->value = ft_strdup(key_value[1]);
	new->next = NULL;
	free2d(key_value);
	return (new);
}

void	add_node(const char *stuff, t_enviro *head)
{
	t_enviro	*teleport;
	char		**key_value;

	teleport = head;
	key_value = split_kv(stuff);
	while (teleport->next != NULL)
		teleport = teleport->next;
	teleport->next = (t_enviro *)malloc(sizeof(t_enviro));
	teleport->next->key = ft_strdup(key_value[0]);
	teleport->next->value = ft_strdup(key_value[1]);
	teleport->next->next = NULL;
	free2d(key_value);
}

t_enviro		*dynamic_node(char *stuff, t_enviro *head)
{
	t_enviro		*teleport;

	teleport = head;
	if (head == NULL)
	{
		head = new_node(stuff);
		teleport = head;
	}
	else
	{
		add_node(stuff, teleport);
		head = teleport;
	}
	return (head);
}

char	**split_kv(const char *array)
{
	char	**key_value;
	int i;
	int j;
	size_t len;

	i = 0;
	j = 0;
	len = ft_strlen(array);
	key_value = (char **)malloc(sizeof(char*) * 3);
	key_value[0] = (char *)malloc(sizeof(char) * len + 1);
	key_value[1] = (char *)malloc(sizeof(char) * len + 1);
	while (array[i] != '=')
	{
		key_value[0][i] = array[i];
		i++;
	}
	key_value[0][i] = '\0';
	i++;
	while (array[i] != '\0')
	{
		key_value[1][j] = array[i];
		i++;
		j++;
	}
	key_value[1][j] = '\0';
	key_value[2] = NULL;
	return (key_value);
}