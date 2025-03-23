/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:11:16 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/23 12:23:42 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}

t_stack	*get_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	is_it_here(int num, int *tab, int min, int max)
{
	int	i;

	i = min;
	while (i < max)
	{
		if (tab[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	get_index(int num, int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (num == tab[i])
			return (i);
	}
	return (0);
}
