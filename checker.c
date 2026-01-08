/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzorolinux <enzorolinux@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:23:42 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/08 18:58:20 by enzorolinux      ###   ########.fr       */
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

static int	void_argument(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] < 33 || argv[i][j] > 126)
		{
			if (argv[i][j] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	exec_move(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strncmp(move, "pa\n", 3))
		push_logic(a, b);
	else if (!ft_strncmp(move, "pb\n", 3))
		push_logic(b, a);
	else if (!ft_strncmp(move, "ra\n", 3))
		rotate_logic(a);
	else if (!ft_strncmp(move, "rb\n", 3))
		rotate_logic(b);
	else if (!ft_strncmp(move, "rr\n", 3))
	{
		rotate_logic(a);
		rotate_logic(b);
	}
	else if (!ft_strncmp(move, "rra\n", 4))
		reverse_rotate_logic(a);
	else if (!ft_strncmp(move, "rrb\n", 4))
		reverse_rotate_logic(b);
	else if (!ft_strncmp(move, "rrr\n", 4))
	{
		reverse_rotate_logic(a);
		reverse_rotate_logic(b);
	}
	else if (!ft_strncmp(move, "sa\n", 3))
		swap_logic(a);
	else if (!ft_strncmp(move, "sb\n", 3))
		swap_logic(b);
	else if (!ft_strncmp(move, "ss\n", 3))
	{
		swap_logic(a);
		swap_logic(b);
	}
	else
		return (0);
	return (1);
}

static int is_sort(t_stack *a, t_stack *b)
{
	if (b != NULL)
		return (0);
	while (a != NULL)
	{
		if (a->prev != NULL)
		{
			if (a->prev->value > a->value)
				return (0);
		}
		a = a->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	char	*move;

	a = NULL;
	b = NULL;
	if (argc < 2 || argument_handling(argv, &a) || void_argument(argc, argv))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	move = get_next_line(0);
	while (move != NULL)
	{
		if (!exec_move(&a, &b, move))
		{
			write(2, "Error\n", 6);
			free_stack(&a);
			free_stack(&b);
			free(move);
			return (1);
		}
		free(move);
		move = get_next_line(0);
	}
	if (is_sort(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	free(move);
	return (0);
}
