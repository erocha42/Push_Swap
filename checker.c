/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:23:42 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/08 14:23:50 by erocha--         ###   ########.fr       */
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
#include "stdio.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	char	**moves;

	a = NULL;
	if (argc < 2 || argument_handling(argv, &a) || void_argument(argc, argv))
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	moves = ft_split(get_next_line(0), ' ');
	printf("%s", moves[1]);
}