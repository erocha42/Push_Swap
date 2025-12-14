/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate__movements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:05:48 by enzorolinux       #+#    #+#             */
/*   Updated: 2025/12/14 17:49:04 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	reverse_rotate_logic(t_stack **stack)
{
	t_stack *last_node;
	t_stack *new_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = get_last_node(*stack);
	new_last = last_node->prev;
	new_last->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	reverse_rotate_a(t_stack **a)
{
	reverse_rotate_logic(a);
	write(1, "rra", 1);
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate_logic(b);
	write(1, "rra", 1);
}

void	reverse_rotate_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate_a(*a);
	reverse_rotate_b(*b);
	write(1, "rrr", 1);
}