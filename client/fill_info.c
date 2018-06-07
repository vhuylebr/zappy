/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fill info client
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

flag_t	flag_table[FLAG_SIZE] =
{
	{"-p", &flag_p},
	{"-n", &flag_n},
	{"-h", &flag_h}
};

static void	init_value(client_info_t *info)
{
	info->port = -1;
	info->name = NULL;
	info->machine = "localhost";
}

int	fill_info(int ac, char **av, client_info_t *info)
{
	int	stock;

	init_value(info);
	for (int i = 1; i < ac; i++) {
		stock = i;
		for (int s = 0; s < FLAG_SIZE; s++) {
			if (!strcmp(flag_table[s].flag, av[i])) {
			        flag_table[s].func(av[i + 1], info);
				i += 1;
			}
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
