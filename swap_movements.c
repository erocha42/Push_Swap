/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:20:40 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/08 18:24:13 by enzorolinux      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	swap_logic(t_stack **stack)
{
	t_stack	*n1;
	t_stack	*n2;
	t_stack	*n3;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	n1 = *stack;
	n2 = n1->next;
	n3 = n2->next;
	n2->prev = NULL;
	n2->next = n1;
	n1->prev = n2;
	n1->next = n3;
	if (n3 != NULL)
		n3->prev = n1;
	(*stack) = n2;
}

void	swap_a(t_stack **a)
{
	swap_logic(a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	swap_logic(b);
	write(1, "sb\n", 3);
}

void	swap_swap(t_stack **a, t_stack **b)
{
	swap_logic(a);
	swap_logic(b);
	write(1, "ss\n", 3);
}
