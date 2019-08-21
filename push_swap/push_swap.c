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

/* static t_node	*ps_lstnew(void const *content, size_t content_size)
{
	t_node	*lst;

	if (!(lst = malloc(sizeof(t_node) * (content_size + 1))))
		return (NULL);
	if (!(lst->dt = malloc(sizeof(TYPE) * (content_size + 1))))
		return (NULL);
	if (content == NULL)
	{
		lst->dt->content = NULL;
		lst->dt->content_size = 0;
	}
	else
	{
		if (!(lst->dt->content = ft_memalloc(content_size)))
		{
			free (lst);
			return (NULL);
		}
		lst->dt->content = ft_memcpy(lst->dt->content, content, content_size);
		lst->dt->content_size = content_size;
	}
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

static void	ps_lstadd(t_node **alst, t_node *new)
{
	t_node	*prev;

	if (!(*alst) || !new)
		return ;
	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	if ((*alst)->prev != NULL)
	{
		prev = (*alst)->prev;
		prev->next = new;
		new->prev = prev;
	}
	new->next = *alst;
	(*alst)->prev = new;
	while ((*alst)->prev != NULL)
		*alst = (*alst)->prev;
}

static void	ps_lstpush(t_node **alst, t_node *new)
{
	if (!(*alst) || !new)
		return ;
	(*alst)->prev = new;
	new->next = *alst;
	*alst = (*alst)->prev;
}

static t_node	*ps_pop(t_node **alst)
{
	t_node	*node_pop;
	t_node	*node_prev;

	if (!(*alst) || !(*alst)->next)
		return (NULL);
	*alst = (*alst)->next;
	node_pop = (*alst)->prev;
	if (node_pop->prev != NULL)
	{
		node_prev = node_pop->prev;
		node_pop->prev = NULL;
		node_prev->next = *alst;
		(*alst)->prev = node_prev;
	}
	else
		(*alst)->prev = NULL;
	node_pop->next = NULL;
	while ((*alst)->prev != NULL)
		*alst = (*alst)->prev;
	return (node_pop);
}

static void	ps_swap(t_node **alst)
{
	t_node	*lst_prev;

	if (!(*alst) || !((*alst)->next))
		return ;
	*alst = (*alst)->next;
	lst_prev = (*alst)->prev;
	lst_prev->prev = *alst;
	lst_prev->next = (*alst)->next;
	lst_prev->next->prev = lst_prev;
	(*alst)->prev = NULL;
	(*alst)->next = lst_prev;
}

static void	ps_knock(t_node **srclst, t_node **dstlst)
{
	ps_lstpush(dstlst, ps_pop(srclst));
}

static void ps_rot(t_node **alst)
{
	t_node	*tmp_lst;

	*alst = (*alst)->next;
	tmp_lst = (*alst)->prev;
	(*alst)->prev = NULL;
	while ((*alst)->next->next != NULL)
		*alst = (*alst)->next;
	tmp_lst->prev = *alst;
	tmp_lst->next = (*alst)->next;
	(*alst)->next = tmp_lst;
	tmp_lst->next->prev = tmp_lst;
	while ((*alst)->prev != NULL)
		*alst = (*alst)->prev;
}

static void ps_revrot(t_node **alst)
{
	t_node	*tmp_lst;

	while ((*alst)->next->next != NULL)
		*alst = (*alst)->next;
	tmp_lst = ps_pop(alst);
	ps_lstpush(alst, tmp_lst);
} */

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
		//else
		//	printf("%s\n", "hello");
		printf("\n");
	}
	printf("%s\t%s\n%s\t%s\n", "_", "_", "a", "b");
}

int	main(int ac, char **av)
{
	t_node	*lst_a;
	t_node	*lst_b;
	int		i;
	char	input[6];

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
		//ps_swap(&lst_a);
		//ps_knock(&lst_a, &lst_b);
		//ps_rot(&lst_a);
		//ps_revrot(&lst_a);
		ps_print(lst_a, lst_b);
		while (fgets(input, 6, stdin))
		{
			ft_find_replace(input, '\n', '\0');
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
		}
	}
	return (0);
}
