/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:41:01 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 18:30:56 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

static void	special_case_handling(t_stack **a, int args_nbr)
{
	if (args_nbr == 1)
		return ;
	else if (args_nbr == 2)
	{
		if ((*a)->value > (*a)->next->value)
			swap_a(a);
	}
	else if (args_nbr == 3)
		sort_three(a);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		args_nbr;

	a = NULL;
	b = NULL;
	if (argc < 2 || argument_handling(argv, &a) || void_argument(argc, argv))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	args_nbr = args_counter(a);
	if (args_nbr < 4)
	{
		special_case_handling(&a, args_nbr);
		free_stack(&a);
		return (0);
	}
	turkish_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
