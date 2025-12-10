/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:01:50 by erocha--          #+#    #+#             */
/*   Updated: 2025/12/10 19:04:18 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int ft_strisdigit(char *str)
{
	int i;

	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	is_doublon(char *str, t_stack **stack)
{
	t_stack *current;
	int		argument_value;

	current = *stack;
	argument_value = ft_atoi(str);
	while (current != NULL)
	{
		if (argument_value == current->value)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	push(char *str, t_stack **stack)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->value = ft_atoi(str);
	new_node->next = *stack;
	*stack = new_node;
}

int	check_error(char **arguments, char *argument, t_stack **stack)
{
	if (!ft_strisdigit(argument))
		return (1);
	if (ft_atol(argument) < INT_MIN || ft_atol(argument) > INT_MAX)
		return (1);
	if (is_doublon(argument, stack))
	{
		ft_free_tab(arguments);
		return (1);
	}
	return (0);
}

int argument_handling(char **argv, t_stack **stack)
{
	char	**arguments;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		arguments = ft_split(argv[i], ' ');
		j = 0;
		while (arguments[j])
		{
			if (check_error(arguments, arguments[j], stack))
				return (1);
			push(arguments[j], stack);
			j++;
		}
		ft_free_tab(arguments);
		i++;
	}
	return (0);
}
