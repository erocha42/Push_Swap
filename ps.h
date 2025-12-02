#ifndef PS_H
# define PS_H

#include <unistd.h>
#include <stdio.h>

int     main(int argc, char **argv);
int     error_argument(char **argv);
long    ft_atol(char *str);
int     ft_strcmp(char *stra, char *strb);

#endif