/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 11:21:41 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 15:03:52 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ps.h>

static int	three_left(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack != NULL)
	{
		stack = stack->next;
		if (i > 3)
			return (0);
		i++;
	}
	return (1);
}

static void	push_to_top(t_stack **stack, t_stack *node, char stack_name)
{
	while (*stack != node)
	{
		if (node->above_median)
		{
			if (stack_name == 'a')
				rotate_a(stack);
			else
				rotate_b(stack);
		}
		else
		{
			if (stack_name == 'a')
				reverse_rotate_a(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

static void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(a);
	while (cheapest_node != *a && cheapest_node->target_node != *b)
	{
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate_rotate(a, b);
		else if (!cheapest_node->above_median
			&& !cheapest_node->target_node->above_median)
			reverse_rotate_rotate(a, b);
		else
			break ;
	}
	push_to_top(a, cheapest_node, 'a');
	push_to_top(b, cheapest_node->target_node, 'b');
	push_b(a, b);
}

static void	push_b_to_a(t_stack **a, t_stack **b)
{
	while ((*a) != (*b)->target_node)
	{
		set_index(*a);
		if ((*b)->target_node->above_median)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	push_a(a, b);
}

void	turkish_sort(t_stack **a, t_stack **b)
{
	push_b(a, b);
	push_b(a, b);
	while (!three_left(*a))
	{
		set_index(*a);
		set_index(*b);
		set_target_a(*a, *b);
		set_target_b(*a, *b);
		set_price(*a, *b);
		set_cheapest(*a);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		set_target_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	push_to_top(a, find_min(*a), 'a');
}
