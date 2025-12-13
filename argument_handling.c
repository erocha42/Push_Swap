/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:01:50 by erocha--          #+#    #+#             */
/*   Updated: 2025/12/13 14:58:20 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int ft_strisdigit(char *str)
{
	int i;

	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* argument_handling.c (Version Corrigée Robuste) */

static int	is_doublon(int *stack, int element)
{
	int i;

	i = 0;
	while (i < element)
	{
		if (stack[i] == stack[element])
			return (1);
		i++;
	}
	return (0);
}

static int	check_error(char **arguments, int index, int **stack, int element)
{
	if (!ft_strisdigit(arguments[index]))
		return (1);
	if (ft_atol(arguments[index]) < INT_MIN || ft_atol(arguments[index]) > INT_MAX)
		return (1);
	(*stack)[element] = ft_atoi(arguments[index]);
	if (is_doublon(*stack, element))
		return (1);
	return (0);
}

int	argument_handling(char **argv, int **stack)
{
	char	**arguments;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		arguments = ft_split(argv[i], ' ');
		j = 0;
		while (arguments[j])
		{
			if (check_error(arguments, j, stack, k))
			{
				ft_free_tab(arguments);
				return (1);
			}
			j++;
			k++;
		}
		ft_free_tab(arguments);
		i++;
	}
	return (0);
}
