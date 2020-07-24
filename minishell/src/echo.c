#include "../includes/minishell.h"

void        print_env_var(t_env *env, char *print)
{
	t_env	*lst;

	lst = env;
	while (lst != NULL)
	{
		if (ft_strcmp(lst->key, to_print) == 0)
		{
            ft_putendl(lst->value);
			break;
		}
		lst = lst->next;
	}
}

char        **get_lines(char type)
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


char       **val_subshell(char **seg, char **exp)
{
    int		i;
    char	*str;
    char	**extra;

    extra = NULL;
    str = NULL;
    i = 0;
    while (seg[i])
    {
        if ((str = strchr(seg[i], '\'')) || (str = strchr(seg[i], '\"')))
           break ;
        i++; 
    }
    if (str)
    {
        extra = get_lines(str[0]);
    }                                                                                     
    *exp = str;
    return (extra);
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

void        print_stuff(t_env *env, char **seg)
{
    int     i;
    char    **subshell;
    char    *exp;

    exp = NULL;
    subshell = val_subshell(seg, &exp);
    i = 1;
    while (seg[i])
    {
        if (seg[i][0] == '$')
        {
            print_env_var(env, &seg[i][1]);
            i++;
            continue ;
        }
        else if (exp)
            do_print(seg[i], exp);
        ft_putstr(seg[i]);
        if (seg[i + 1] != NULL)
            ft_putstr(" "); 
        i++;
    }
    ft_putstr("\n");
    if (subshell)
        print_subshell(subshell, exp);
}

void        ft_echo(t_env *env, char *buffer)
{
    char **args;

    args = ft_strsplit(buffer, ' ');
    print_stuff(env, args);
    free2d(args);
}
