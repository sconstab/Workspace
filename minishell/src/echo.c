#include "../includes/minishell.h"

void        print_env_var(t_enviro *env, char *to_print)
{
	t_enviro	*tmp;

	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, to_print) == 0)
		{
            ft_putendl(tmp->value);
			break;
		}
		tmp = tmp->next;
	}
}

char        **get_next_next_lines(char type)
{
    char    *str;
    char    **array;

    array = NULL;
    while (42)
    {
        write(1, ">", 1);
        str = read_line();
        if (strchr(str, type))
        {
            array = arraypush(array, str);
            free(str);
            break;
        }
        array = arraypush(array, str);
        free(str);
    }
    return (array);
}


char       **validate_subshell(char **segments, char **exp)
{
    int i;
    char *type;
    char **extra_lines;

    extra_lines = NULL;
    type = NULL;
    i = 0;
    while (segments[i])
    {
        if ((type = strchr(segments[i], '\'')) || (type = strchr(segments[i], '\"')))
           break ;
        i++; 
    }
    if (type)
    {
        extra_lines = get_next_next_lines(type[0]);
    }                                                                                     
    *exp = type;
    return (extra_lines);
}

void        do_print(char *str, char *exp)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] == exp[0])
        {
            i++;
            continue ;
        }
        write(1, &str[i], 1);
        i++;
    }
}

void        print_subshell(char **subshell, char *exp)
{
    int i;

    i = 0;
    while (subshell[i])
    {
        if (exp)
        {
            do_print(subshell[i], exp);
            ft_putstr("\n");
        }
        i++;
    }
    free2d(subshell);
}

void        print_stuff(t_enviro *env, char **segments)
{
    int     i;
    char    **subshell;
    char    *exp;

    exp = NULL;
    subshell = validate_subshell(segments, &exp);
    i = 1;
    while (segments[i])
    {
        if (segments[i][0] == '$')
        {
            print_env_var(env, &segments[i][1]);
            i++;
            continue ;
        }
        else if (exp)
            do_print(segments[i], exp);
        ft_putstr(segments[i]);
        if (segments[i + 1] != NULL)
            ft_putstr(" "); 
        i++;
    }
    ft_putstr("\n");
    if (subshell)
        print_subshell(subshell, exp);

}

void        ft_echo(t_enviro *env, char *buffer)
{
    char **args;

    args =ft_strsplit(buffer, ' ');
    print_stuff(env, args);
    free2d(args);
}
