/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:16:20 by erocha--          #+#    #+#             */
/*   Updated: 2026/01/06 15:42:11 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <unistd.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		main(int argc, char **argv);
int		argument_handling(char **argv, t_stack **stack);
long	ft_atol(char *str);
void	ft_free_tab(char **tab);
t_stack	*get_last_node(t_stack *stack);
int		args_counter(t_stack *a);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_rotate(t_stack **a, t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_rotate(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	swap_swap(t_stack **a, t_stack **b);
void	turkish_sort(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
t_stack	*get_cheapest(t_stack **a);
int		get_stack_size(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	price_double_handling(t_stack *a, int size_a, int size_b);
void	set_index(t_stack *stack);
void	set_target_b(t_stack *a, t_stack *b);
void	set_target_a(t_stack *a, t_stack *b);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *a);

#endif
