/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:07:45 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/23 12:07:48 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack **stack_b)
{
	int	tmp;

	if (!*stack_b || !(*stack_b)->next)
		return (0);
	tmp = (*stack_b)->num;
	(*stack_b)->num = (*stack_b)->next->num;
	(*stack_b)->next->num = tmp;
	write(1, "sb\n", 3);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return (0);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
	write(1, "pb\n", 3);
	return (0);
}

int	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return (0);
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	last = get_last(*stack_b);
	last->next = tmp;
	write(1, "rb\n", 3);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return (0);
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, last);
	write(1, "rrb\n", 4);
	return (0);
}
