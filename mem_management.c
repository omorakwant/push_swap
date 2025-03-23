/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:30:32 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/23 12:12:43 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_args(char **args)
{
	int	i;

	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (0);
}

int	stack_free(t_data *data)
{
	t_stack	*current;
	t_stack	*next;

	if (!data)
		return (0);
	current = data->stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (data->tab)
		free(data->tab);
	free(data);
	return (0);
}

void	free_exit(t_data *a, t_data *b, char **args)
{
	free_args(args);
	stack_free(a);
	stack_free(b);
}
