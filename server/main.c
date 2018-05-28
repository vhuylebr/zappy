/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** main server file
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

int	main(int ac, char **av)
{
	info_t	*info = malloc(sizeof(info_t));

	if (info == NULL || fill_info(ac, av, info) == 84)
		return (84);
	printf("port = %d\nwidth = %d\nheight = %d\ncli = %d\nfreq = %d\n", info->port, info->width, info->height, info->nb_cli, info->freq);
	return (0);
}
