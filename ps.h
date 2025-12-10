#ifndef PS_H
#define PS_H

#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
} t_stack;

int main(int argc, char **argv);
int argument_handling(char **argv, t_stack **stack);
long ft_atol(char *str);
void ft_free_tab(char **tab);

#endif
