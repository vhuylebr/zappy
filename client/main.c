/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** client main
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "client.h"

static int	display_help(void)
{
	int	fd = open("client/help.txt", O_RDONLY);
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

int	main(int ac, char **av)
{
	client_info_t	*info = malloc(sizeof(client_info_t));

	if (ac > 1 && !strcmp(av[1], "-help"))
		return (display_help());	
	else if (info == NULL || fill_info(ac, av, info) == 84)
		return (84);
	else if (info->port == -1 || info->name == NULL)
		return (my_perror(MISS_FLAG, 84));
	printf("port = %d\nname = %s\nmachine = %s\n", info->port, info->name, info->machine);
	return (0);
}
