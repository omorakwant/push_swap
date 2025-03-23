/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:04:33 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/23 12:07:58 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	continue_sort(t_stack **a, int index, t_stack *last)
{
	if (index == 1)
	{
		if ((*a)->num > last->num)
			ra(a);
		else
			sa(a);
	}
	else if (index == 2)
	{
		if ((*a)->num > (*a)->next->num)
		{
			sa(a);
			rra(a);
		}
		else
			rra(a);
	}
}

void	sort_three(t_stack **a)
{
	int		index;
	t_stack	*last;

	if (is_sorted(*a))
		return ;
	last = ft_lstlast(*a);
	index = ft_index(*a, ft_min(*a));
	if (index == 0)
	{
		sa(a);
		ra(a);
	}
	else
		continue_sort(a, index, last);
}

void	sort_four(t_stack **a, t_stack **b, t_data *data)
{
	int	index;

	if (is_sorted(*a))
		return ;
	data->size = ft_lstsize(*a);
	index = ft_index(*a, ft_min(*a));
	if (index <= data->size / 2)
		while (index-- > 0)
			ra(a);
	else
		while (index++ < data->size)
			rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b, t_data *data)
{
	int	index;

	data->size = ft_lstsize(*a);
	index = ft_index(*a, ft_min(*a));
	if (index <= data->size / 2)
		while (index-- > 0)
			ra(a);
	else
		while (index++ < data->size)
			rra(a);
	pb(a, b);
	sort_four(a, b, data);
	pa(a, b);
}
