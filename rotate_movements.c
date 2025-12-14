/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:06:13 by enzorolinux       #+#    #+#             */
/*   Updated: 2025/12/14 18:31:58 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	rotate_logic(t_stack **stack)
{
	t_stack *last;
	t_stack *node_to_move;

	node_to_move = *stack;
	last = get_last_node(*stack);
	node_to_move->prev = last;
	node_to_move->next = NULL;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
}