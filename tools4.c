/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:14:51 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/23 12:15:05 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*tmp;

	tmp = lst;
	i = 0;
	if (!lst)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_index(t_stack *stack, int num)
{
	int		index;
	t_stack	*tmp;

	tmp = stack;
	index = 0;
	while (tmp)
	{
		if (num == tmp->num)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	ft_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack;
	max = stack->num;
	while (tmp)
	{
		if (max < tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	tmp = stack->next;
	min = stack->num;
	while (tmp)
	{
		if (min > tmp->num)
			min = tmp->num;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
