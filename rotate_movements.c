/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:19:19 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/08 18:24:07 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	rotate_logic(t_stack **stack)
{
	t_stack	*last;
	t_stack	*node_to_move;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = get_last_node(*stack);
	node_to_move = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	node_to_move->prev = last;
	node_to_move->next = NULL;
	last->next = node_to_move;
}

void	rotate_a(t_stack **a)
{
	rotate_logic(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	rotate_logic(b);
	write(1, "rb\n", 3);
}

void	rotate_rotate(t_stack **a, t_stack **b)
{
	rotate_logic(a);
	rotate_logic(b);
	write(1, "rr\n", 3);
}
