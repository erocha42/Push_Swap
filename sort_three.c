/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 14:11:51 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 15:21:00 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sort_three(t_stack **a)
{
	if (args_counter(*a) > 2)
	{
		if ((*a)->value > (*a)->next->value
			&& (*a)->value > (*a)->next->next->value)
			rotate_a(a);
		else if ((*a)->next->value > (*a)->value
			&& (*a)->next->value > (*a)->next->next->value)
			reverse_rotate_a(a);
	}
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
}
