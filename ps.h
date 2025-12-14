#ifndef PS_H
#define PS_H

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}                   t_stack;

int main(int argc, char **argv);
int argument_handling(char **argv, t_stack **stack);
long ft_atol(char *str);
void ft_free_tab(char **tab);
t_stack *get_last_node(t_stack *stack);

#endif
