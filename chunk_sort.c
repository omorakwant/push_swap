/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:01:55 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/23 12:29:27 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *a, t_data *b)
{
	if (a->size == 2)
		sa(&a->stack);
	else if (a->size == 3)
		sort_three(&a->stack);
	else if (a->size == 4)
		sort_four(&a->stack, &b->stack, a);
	else if (a->size == 5)
		sort_five(&a->stack, &b->stack, a);
	else
		sort_chunks(&a->stack, &b->stack, a);
}

void	push_max(t_stack **a, t_stack **b)
{
	int	index;
	int	size;

	size = ft_lstsize(*b);
	index = ft_index(*b, ft_max(*b));
	if (index <= size / 2)
		while ((*b)->num != ft_max(*b))
			rb(b);
	else
		while ((*b)->num != ft_max(*b))
			rrb(b);
	pa(a, b);
}

int	set_range(t_stack *stack, t_data *data)
{
	int	range;

	if (data->size <= 16)
		range = 5;
	else if (data->size <= 100)
		range = 15;
	else
		range = 40;
	return (range);
}

void	sort_chunks(t_stack **a, t_stack **b, t_data *data)
{
	data->range = set_range(*a, data);
	data->size = ft_lstsize(*a);
	while (*a)
	{
		if (is_it_here((*a)->num, data->tab, data->min, data->range))
		{
			pb(a, b);
			if (data->range < data->size)
				data->range++;
			data->min++;
		}
		else if ((*a)->num < data->tab[data->min])
		{
			pb(a, b);
			rb(b);
			if (data->range < data->size)
				data->range++;
			data->min++;
		}
		else
			ra(a);
	}
	while (*b)
		push_max(a, b);
}
