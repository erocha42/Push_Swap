/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:52:59 by erocha--          #+#    #+#             */
/*   Updated: 2025/12/13 17:04:52 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int *push_top(int *stack, int size)
{
	int *new_stack;
	int i;

	new_stack = malloc(sizeof(int) * (size + 1));
	i = 0;
	new_stack[0] = 0;
	while (i < size)
	{
		new_stack[i + 1] = stack[i];
		i++;
	}
	return (new_stack);
}

static int *pop_top(int *stack, int size)
{
	int *new_stack;
	int i;

	new_stack = malloc(sizeof(int) * (size - 1));
	i = 0;
	while (i < size - 1)
	{
		new_stack[i] = stack[i + 1];
		i++;
	}
	return (new_stack);
}

void push_a(int **a, int **b, int *size_a, int *size_b)
{
	int *old_a;
	int *old_b;

	old_a = *a;
	old_b = *b;
	if (*size_b == 0)
		return ;
	*a = push_top(*a, *size_a);
	(*size_a)++;
	(*a)[0] = (*b)[0];
	free(old_a);
	*b = pop_top(*b, *size_b);
	(*size_b)--;
	free(old_b);
	write(1, "pa\n", 3);
}

/*void push_b(t_stack **a, t_stack **b)
{
	t_stack	*node_to_move;

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
}*/
