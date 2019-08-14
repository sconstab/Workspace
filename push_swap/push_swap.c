/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sconstab <sconstab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:29:43 by sconstab          #+#    #+#             */
/*   Updated: 2019/08/14 12:02:07 by sconstab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static t_ps	*ps_lstnew(void const *content, size_t content_size)
{
	t_ps	*lst;

	if (!(lst = malloc(sizeof(t_ps) * (content_size + 1))))
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		if (!(lst->content = ft_memalloc(sizeof(content_size))))
		{
			free (lst);
			return (NULL);
		}
		lst->content = ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

static void	ps_lstadd(t_ps **alst, t_ps *new)
{
	t_ps	*prev;
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

static void	ps_lstpush(t_ps **alst, t_ps *new)
{
	if (!(*alst) || !new)
		return ;
	(*alst)->prev = new;
	new->next = *alst;
	*alst = (*alst)->prev;
}

static t_ps	*ps_pop(t_ps **alst)
{
	t_ps	*lstnode;

	if (!(*alst)->next || !(*alst))
		return (NULL);
	*alst = (*alst)->next;
	lstnode = (*alst)->prev;
	lstnode->next = NULL;
	(*alst)->prev = NULL;
	return (lstnode);
}

static t_ps	*ps_popindex(t_ps **alst, unsigned int index)
{
	int		i;
	t_ps	*lstnode;

	i = 0;
	lstnode = NULL;
	if (!alst || !index)
		return (NULL);
	if (index == 0)
		return (ps_pop(alst));
	while (i < index)
	{
		if ((*alst)->next == NULL)
			return (NULL);
		*alst = (*alst)->next;
		i++;
	}
	lstnode = *alst;
	free (*alst);
	lstnode->next->prev = lstnode->prev;
	lstnode->prev->next = lstnode->next;
	*alst = lstnode->prev;
	while ((*alst)->prev != NULL)
		*alst = (*alst)->prev;
	lstnode->prev = NULL;
	lstnode->next = NULL;
	return (lstnode);
}

static void	ps_swap(t_ps **alst)
{
	t_ps	*lst_prev;

	lst_prev = *alst;
	if (!(*alst) || !((*alst)->next))
		return ;
	*alst = (*alst)->next;
	lst_prev->prev = *alst;
	lst_prev->next = (*alst)->next;
	(*alst)->prev = NULL;
	(*alst)->next = lst_prev;
}

static void	ps_knock(t_ps **srclst, t_ps **dstlst)
{
	t_ps	*tmp;
	if (!(tmp = ps_pop(srclst)))
		return ;
	tmp->next = *dstlst;
	(*dstlst)->prev = tmp;
	*dstlst = (*dstlst)->prev;
}

static void ps_rot(t_ps **alst)
{
	t_ps	*tmp_lst;

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

static void ps_revrot(t_ps **alst)
{
	t_ps	*tmp_lst;

	while ((*alst)->next->next != NULL)
		*alst = (*alst)->next;
	tmp_lst = (*alst)->next;
	tmp_lst->prev->next = NULL;
	tmp_lst->prev = NULL;
	while ((*alst)->prev != NULL)
		*alst = (*alst)->prev;
	tmp_lst->next = *alst;
	(*alst)->prev = tmp_lst;
	*alst = (*alst)->prev;
}

static void ps_print(t_ps *alst, t_ps *blst)
{
	printf("%s\n", "Init a and b:");
	while (alst->next != NULL || blst->next != NULL)
	{
		if (alst->next != NULL)
		{
			printf("%s", alst->content);
			alst = alst->next;
		}
		if (blst->next != NULL)
		{
			printf("\t%s", blst->content);
			blst = blst->next;
		}
		printf("\n");
	}
	printf("%s\t%s\n%s\t%s\n", "_", "_", "a", "b");
}

int	main(int ac, char **av)
{
	t_ps	*lst_a;
	t_ps	*lst_b;
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
			ps_print(lst_a, lst_b);
		}
	}
	return (0);
}