/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-- <erocha--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:02:09 by erocha--          #+#    #+#             */
/*   Updated: 2025/12/12 21:54:32 by erocha--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

#include "stdio.h"

static int	sizeofarg(int argc, char **argv)
{
	int i;
	int args;

	i = 1;
	args = 0;
	while (i < argc)
	{
		args = args + count_word(argv[i], ' ');
		i++;
	}
	return (args);
}

int	main(int argc, char **argv)
{
	int	*a;
	/*int	*b;*/

	a = malloc(sizeof(int) * sizeofarg(argc, argv));
	if (argc < 2 || argument_handling(argv, &a))
	{
		write(2, "Error\n", 6);
		free(a);
		return (1);
	}
	free(a);
	return (0);
}
