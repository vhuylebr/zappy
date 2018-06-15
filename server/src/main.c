/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** main server file
*/

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"

static int	display_help(void)
{
	int	fd = open("server/help.txt", O_RDONLY);
	char	buff[4096];
	int	len;

	if (fd != -1) {
		len = read(fd, buff, 4096);
		buff[len] = '\0';
		printf("%s\n", buff);
		close(fd);
	}
	return (0);
}

static void loop(info_t *info)
{
	while (1) {
		handle_clients(info);
	}
}

int	main(int ac, char **av)
{
	info_t *info = malloc(sizeof(info_t));

	info->clients = NULL;
	info->gui = NULL;
	info->id = 0;
	if (ac > 1 && !strcmp(av[1], "-help"))
		return (display_help());
	else if (info == NULL || fill_info(ac, av, info) == 84)
		return (84);
	else if (info->team == NULL)
		return (my_perror(MISS_FLAG, 84));
	for (int i = 0; info->team[i]; i++)
		info->team[i]->nb_cli = info->nb_cli;
	srand(time(NULL));
	init_serveur(info->port, &info->server);
	init_map(info);
	loop(info);
	return (0);
}
