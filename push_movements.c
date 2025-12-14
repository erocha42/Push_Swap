/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:52:59 by erocha--          #+#    #+#             */
/*   Updated: 2025/12/14 13:04:27 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void push_a(t_stack **a, t_stack **b)
{
	t_stack *node_to_move;

	if (*b == NULL)
		return ;
	node_to_move = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	node_to_move->next = *a;
	node_to_move->prev = NULL;
	if (*a != NULL)
		(*a)->prev = node_to_move;
	*a = node_to_move;
	write(1, "pa\n", 3);
}

void push_b(t_stack **a, t_stack **b)
{
	t_stack *node_to_move;

	if (*a == NULL)
		return ;
	node_to_move = *a;
	*a = (*a)->next;
	if (*a != NULL)
	(*a)->prev = NULL;
	node_to_move->next = *b;
	node_to_move->prev = NULL;
	if (*b != NULL)
		(*b)->prev = node_to_move;
	*b = node_to_move;
	write(1, "pb\n", 3);
}
