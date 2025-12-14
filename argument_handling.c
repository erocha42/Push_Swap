/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:01:50 by erocha--          #+#    #+#             */
/*   Updated: 2025/12/14 18:02:26 by enzorolinux      ###   ########.fr       */
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

int check_error(char **arguments, int index, t_stack **stack)
{
	if (!ft_strisdigit(arguments[index]))
		return (1);
	if (ft_atol(arguments[index]) < INT_MIN || ft_atol(arguments[index]) > INT_MAX)
		return (1);
	if (is_doublon(arguments[index], stack))
	{
		ft_free_tab(arguments);
		return (1);
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
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
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
			push(arguments[j], stack);
			j++;
		}
		ft_free_tab(arguments);
		i++;
	}
	return (0);
}
