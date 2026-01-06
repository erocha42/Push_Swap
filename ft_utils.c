/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:13:04 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 15:15:32 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

long	ft_atol(char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	args_counter(t_stack *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack	*get_cheapest(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current != NULL)
	{
		if (current->cheapest == 1)
			return (current);
		current = current->next;
	}
	return (current);
}
