/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 06:23:32 by odahriz           #+#    #+#             */
/*   Updated: 2025/03/24 12:26:24 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	input_to_stack(char **av, int ac, t_data **data)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	(void)ac;
	(*data)->stack = malloc(sizeof(t_stack));
	if (!(*data)->stack)
		return (0);
	(*data)->stack->num = ft_atoi(av[0]);
	(*data)->stack->next = NULL;
	tmp = (*data)->stack;
	while (av[i])
	{
		tmp->next = malloc(sizeof(t_stack));
		if (!tmp->next)
			return (0);
		tmp = tmp->next;
		tmp->num = ft_atoi(av[i]);
		tmp->next = NULL;
		i++;
	}
	(*data)->size = count_size(av);
	get_arr((*data)->stack, data);
	return (0);
}

t_data	*stack_init(void)
{
	t_data	*stack;

	stack = malloc(sizeof(t_data));
	if (!stack)
		return (NULL);
	stack->stack = NULL;
	stack->max = 0;
	stack->min = 0;
	stack->range = 0;
	stack->size = 0;
	stack->tab = 0;
	return (stack);
}

char	**av_filter(char **av)
{
	int		i;
	char	*str;
	char	*tmp;
	char	**args;

	if (!av[0] || !av[0][0])
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	i = 0;
	str = ft_strdup(av[i]);
	i++;
	while (av[i])
	{
		tmp = ft_strjoin(str, av[i]);
		free(str);
		if (!tmp || !av[i][0])
			return (NULL);
		str = tmp;
		i++;
	}
	args = ft_split(tmp, ' ');
	free(tmp);
	return (args);
}

int	main(int ac, char **av)
{
	t_data	*a;
	t_data	*b;
	char	**args;

	if (ac < 3)
		return (0);
	a = stack_init();
	b = stack_init();
	if (!a || !b)
		return (0);
	args = av_filter(av + 1);
	if (args == NULL)
		return (1);
	input_to_stack(args, ac - 1, &a);
	if (is_sorted(a->stack))
		return (0);
	if (!checker(a, args) || !is_int(args))
	{
		write(2, "Error\n", 6);
		free_exit(a, b, args);
		exit(1);
	}
	sort(a, b);
	free_exit(a, b, args);
	return (0);
}
