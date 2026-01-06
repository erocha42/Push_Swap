/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:19:12 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 15:19:13 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	reverse_rotate_logic(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*new_last;

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
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **b)
{
	reverse_rotate_logic(b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate_logic(a);
	reverse_rotate_logic(b);
	write(1, "rrr\n", 4);
}
