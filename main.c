/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:02:09 by erocha--          #+#    #+#             */
/*   Updated: 2025/12/10 18:46:30 by erocha--         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc < 2 || argument_handling(argv, &a))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	free_stack(&a);
	return (0);
}
