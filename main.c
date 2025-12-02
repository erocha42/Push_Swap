#include "ps.h"

int	main(int argc, char **argv)
{
	if (argc < 2 || error_argument(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
