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

int	ft_strcmp(char *stra, char *strb)
{
	int	i;

	i = 0;
	while (stra[i] == strb[i] && stra[i] && strb[i])
		i++;
	return (stra[i] - strb[i]);
}
