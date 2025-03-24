/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:06:56 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/24 12:25:20 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **stack_a)
{
	int	tmp;

	if (!*stack_a || !(*stack_a)->next)
		return (0);
	tmp = (*stack_a)->num;
	(*stack_a)->num = (*stack_a)->next->num;
	(*stack_a)->next->num = tmp;
	write(1, "sa\n", 3);
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_b)
		return (0);
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
	write(1, "pa\n", 3);
	return (0);
}

int	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return (0);
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	last = get_last(*stack_a);
	last->next = tmp;
	write(1, "ra\n", 3);
	return (0);
}

int	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return (0);
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, last);
	write(1, "rra\n", 4);
	return (0);
}
