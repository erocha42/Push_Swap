/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:11:56 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 18:31:16 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	ft_strisdigit(char *str)
{
	int	i;

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
	t_stack	*current;
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

static int	check_error(char *argument, t_stack **stack)
{
	if (!ft_strisdigit(argument))
		return (1);
	if (ft_atol(argument) < INT_MIN || ft_atol(argument) > INT_MAX)
		return (1);
	if (is_doublon(argument, stack))
		return (1);
	return (0);
}

static void	push_init(char *str, t_stack **stack)
{
	t_stack	*current;
	t_stack	*new_node;

	current = get_last_node(*stack);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->prev = current;
	new_node->value = ft_atoi(str);
	new_node->next = NULL;
	if (*stack != NULL)
		current->next = new_node;
	else
		*stack = new_node;
}

int	argument_handling(char **argv, t_stack **stack)
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
			if (check_error(arguments[j], stack))
			{
				ft_free_tab(arguments);
				return (1);
			}
			push_init(arguments[j], stack);
			j++;
		}
		ft_free_tab(arguments);
		i++;
	}
	return (0);
}
