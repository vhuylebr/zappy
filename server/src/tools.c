/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server tools
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

static int	check_is_number(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	return (0);
}

int	flag_cmd(char **av, int i, int *var)
{
	if (!av[i + 1] || check_is_number(av[i + 1]) == -1)
		return (-1);
	*var = atoi(av[i + 1]);
	return (i + 1);
}


int	my_perror(char *str, int ret)
{
	dprintf(2, "%s", str);
	return (ret);
}

int	get_max_fd(client_t *clients)
{
	client_t	*tmp;
	int		stock = 0;

	if (clients == NULL)
		return (4);
	for (tmp = clients; tmp; tmp = tmp->next) {
		if (tmp->fd > stock)
			stock = tmp->fd;
	}
	if (stock <= 3)
		return (4);
	return (stock + 1);
}

void	print_ressources(int r[7], int fd)
{
	dprintf(fd, "%d %d %d %d %d %d %d\n", r[0],
	r[1], r[2], r[3], r[4], r[5], r[6]);
}