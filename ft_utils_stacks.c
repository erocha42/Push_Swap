/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:34:30 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 15:33:53 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	get_stack_size(t_stack *stack)
{
	int	stack_nbr;

	stack_nbr = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		stack_nbr++;
	}
	return (stack_nbr);
}

t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack != NULL)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack != NULL)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	price_double_handling(t_stack *a, int size_a, int size_b)
{
	if (a->above_median && a->target_node->above_median)
	{
		if (a->index < a->target_node->index)
			a->push_cost -= a->index;
		else
			a->push_cost -= a->target_node->index;
	}
	else if (!(a->above_median) && !(a->target_node->above_median))
	{
		if ((size_a - a->index)
			< (size_b - a->target_node->index))
			a->push_cost -= size_a - a->index;
		else
			a->push_cost -= size_b - a->target_node->index;
	}
}
