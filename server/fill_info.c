/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fill info
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

flag_t	flag_table[FLAG_SIZE] =
{
	{"-p", &flag_p},
	{"-x", &flag_x},
	{"-y", &flag_y},
	{"-n", &flag_n},
	{"-c", &flag_c},
	{"-f", &flag_f}
};

int	flag_n(char **av, int i, info_t *info)
{
	(void)av;(void)i;(void)info;
        for (i = i + 1; av[i][0] != '-' && av[i]; i++);
	return (i - 1);
}

int	fill_info(int ac, char **av, info_t *info)
{
	int	stock;

	for (int i = 1; i < ac; i++) {
		stock = i;
		for (int s = 0; s < FLAG_SIZE; s++) {
			if (!strcmp(flag_table[s].flag, av[i]))
				i = flag_table[s].func(av, i, info);
		}
		if (stock == i)
			return (my_perror("Invalid flags\n", 84));
		else if (i == -1) {
			dprintf(2, "%s: problem with this arguments\n", av[stock]);
			return (84);
		}
	}
	return (0);
}
