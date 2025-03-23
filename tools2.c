/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:23:21 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/23 12:29:31 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i][j] == '-' || s[i][j] == '+')
			j++;
		if (s[i][j] == '\0')
			return (0);
		while (s[i][j])
		{
			if (!(s[i][j] >= '0' && s[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_max(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_atoi(args[i]) > 2147483647 || ft_atoi(args[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	is_dup(t_data *stack)
{
	int	i;
	int	j;
	int	size;

	size = stack->size;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->tab[i] == stack->tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checker(t_data *stack, char **args)
{
	int	i;

	i = 0;
	if (is_dup(stack) || is_max(args))
		return (0);
	if (is_sorted(stack->stack))
		return (0);
	return (1);
}
