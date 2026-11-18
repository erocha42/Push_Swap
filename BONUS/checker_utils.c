/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:05:57 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/12 13:06:24 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "GNL/get_next_line.h"

static void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int	extended_move_exec(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "rr\n", 3))
	{
		rotate_logic(a);
		rotate_logic(b);
	}
	else if (!ft_strncmp(move, "rrr\n", 4))
	{
		reverse_rotate_logic(a);
		reverse_rotate_logic(b);
	}
	else if (!ft_strncmp(move, "ss\n", 3))
	{
		swap_logic(a);
		swap_logic(b);
	}
	else
		return (0);
	return (1);
}

int	check_movements(t_stack **a, t_stack **b, char *move)
{
	while (move != NULL)
	{
		if (!move_exec(a, b, move))
		{
			write(2, "Error\n", 6);
			free_stack(a);
			free_stack(b);
			free(move);
			return (0);
		}
		free(move);
		move = get_next_line(0);
	}
	return (1);
}
