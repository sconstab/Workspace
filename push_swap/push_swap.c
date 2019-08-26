/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:29:43 by sconstab          #+#    #+#             */
/*   Updated: 2019/08/20 11:08:18 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static void ps_print(t_node *alst, t_node *blst)
{
	printf("%s\n", "Init a and b:");
	while (alst->next != NULL || blst->next != NULL)
	{
		if (alst->next != NULL)
		{
			printf("%s", alst->dt->content);
			alst = alst->next;
		}
		if (blst->next != NULL)
		{
			printf("\t%s", blst->dt->content);
			blst = blst->next;
		}
		printf("\n");
	}
	printf("%s\t%s\n%s\t%s\n", "_", "_", "a", "b");
}

int	main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;
	t_node	*last;
	int		i;
	char	*input;

	i = 1;
	if (ac >= 2)
	{
		lst_a = ps_lstnew(NULL, 0);
		lst_b = ps_lstnew(NULL, 0);
		while (i < ac)
		{
			ps_lstadd(&lst_a, ps_lstnew(av[i], ft_strlen(av[i])));
			i++;
		}
		ps_print(lst_a, lst_b);
		/*while (get_next_line(1, &input))
		{
			if (ft_strcmp(input, "sa") == 0 || ft_strcmp(input, "ss") == 0)
				ps_swap(&lst_a);
			if (ft_strcmp(input, "sb") == 0 || ft_strcmp(input, "ss") == 0)
				ps_swap(&lst_b);
			if (ft_strcmp(input, "pa") == 0)
				ps_knock(&lst_b, &lst_a);
			if (ft_strcmp(input, "pb") == 0)
				ps_knock(&lst_a, &lst_b);
			if (ft_strcmp(input, "ra") == 0 || ft_strcmp(input, "rr") == 0)
				ps_rot(&lst_a);
			if (ft_strcmp(input, "rb") == 0 || ft_strcmp(input, "rr") == 0)
				ps_rot(&lst_b);
			if (ft_strcmp(input, "rra") == 0 || ft_strcmp(input, "rrr") == 0)
				ps_revrot(&lst_a);
			if (ft_strcmp(input, "rrb") == 0 || ft_strcmp(input, "rrr") == 0)
				ps_revrot(&lst_b);
			if (ft_strcmp(input, "exit") == 0)
				return (0);
			//if (ft_strcmp(input, "print") == 0)
				ps_print(lst_a, lst_b);
		}*/
		i = 0;
		while (i == 0)
		{
			last = lst_a->next;
			while (last->next->next != NULL)
				last = last->next;
			if (lst_b->next->next != NULL)
			{
				if (ft_atoi(lst_b->dt->content) < ft_atoi(lst_b->next->dt->content))
					ps_swap(&lst_b);
			}
			else if (lst_a->next->next != NULL)
			{
				if (ft_atoi(lst_a->dt->content) > ft_atoi(lst_a->next->dt->content))
					ps_swap(&lst_a);
				if (ft_atoi(lst_a->dt->content) > ft_atoi(last))
			}
			else
				ps_knock(&lst_a, &lst_b);
			ps_print(lst_a, lst_b);
			sleep(5);
			if (lst_a->next == NULL)
				break ;
		}
	}
	return (0);
}
