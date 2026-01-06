/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 19:02:24 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 18:31:46 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	set_index(t_stack *stack)
{
	int		i;
	int		median;

	i = 0;
	median = get_stack_size(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	int		best_match;
	int		find_target;

	while (a != NULL)
	{
		best_match = INT_MIN;
		current_b = b;
		find_target = 0;
		while (current_b != NULL)
		{
			if (current_b->value < a->value && current_b->value > best_match)
			{
				best_match = current_b->value;
				a->target_node = current_b;
				find_target = 1;
			}
			current_b = current_b->next;
		}
		if (find_target == 0)
			a->target_node = find_max(b);
		a = a->next;
	}
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	int		best_match;
	int		find_target;

	while (b != NULL)
	{
		best_match = INT_MAX;
		current_a = a;
		find_target = 0;
		while (current_a != NULL)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				b->target_node = current_a;
				find_target = 1;
			}
			current_a = current_a->next;
		}
		if (find_target == 0)
			b->target_node = find_min(a);
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	stack_size_a;
	int	stack_size_b;

	stack_size_a = get_stack_size(a);
	stack_size_b = get_stack_size(b);
	while (a != NULL)
	{
		a->push_cost = 0;
		if (a->above_median)
			a->push_cost = a->index;
		else
			a->push_cost = (stack_size_a - a->index);
		if (a->target_node->above_median)
			a->push_cost += (a->target_node->index);
		else
			a->push_cost += (stack_size_b - a->target_node->index);
		price_double_handling(a, stack_size_a, stack_size_b);
		a = a->next;
	}
}

void	set_cheapest(t_stack *a)
{
	long	best_cost;
	t_stack	*cheapest_node;

	best_cost = INT_MAX;
	cheapest_node = NULL;
	while (a != NULL)
	{
		a->cheapest = 0;
		if (a->push_cost <= best_cost)
		{
			best_cost = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = 1;
}
