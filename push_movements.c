/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:18:34 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 15:18:52 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	push_logic(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_to_move;

	if (*stack_b == NULL)
		return ;
	node_to_move = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b != NULL)
		(*stack_b)->prev = NULL;
	node_to_move->next = *stack_a;
	node_to_move->prev = NULL;
	if (*stack_a != NULL)
		(*stack_a)->prev = node_to_move;
	*stack_a = node_to_move;
}

void	push_a(t_stack **a, t_stack **b)
{
	push_logic(a, b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	push_logic(b, a);
	write(1, "pb\n", 3);
}
