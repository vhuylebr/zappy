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
	get_client(info);
	while (1) {
		printf("getclient\n");
		get_client(info);
		if (info->clients) {
			handle_clients(info);
		}
	}
}

int	main(int ac, char **av)
{
	info_t *info = malloc(sizeof(info_t));

	if (ac > 1 && !strcmp(av[1], "-help"))
		return (display_help());
	else if (info == NULL || fill_info(ac, av, info) == 84)
		return (84);
	else if (info->port == -1 || info->width == -1 || info->height == -1)
		return (my_perror(MISS_FLAG, 84));
	else if (info->nb_cli == -1 || info->name == NULL || info->freq == -1)
		return (my_perror(MISS_FLAG, 84));
	init_serveur(info->port, &info->server);
	printf("port = %d\nwidth = %d\nheight = %d\ncli = %d\nfreq = %d\nserver %d\n", info->port, info->width, info->height, info->nb_cli, info->freq, info->server.fd);
	loop(info);
	return (0);
}
