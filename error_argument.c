#include "ps.h"

int error_argument(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return (1);
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(argv[j], argv[i]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
