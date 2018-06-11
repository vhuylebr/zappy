/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle clients
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

static void add_client(info_t *info, int fd)
{
	client_t *tmp = malloc(sizeof(client_t));

	if (info->clients == NULL) {
		info->clients = tmp;
		info->clients->next = NULL;
	} else {
		tmp->next = info->clients;
		info->clients = tmp;
	}
	info->clients->fd = fd;
}

void	get_client(info_t *info)
{
	int client_fd = accept(info->server.fd,
		(struct sockaddr *)&info->server.s_in_client,
			&info->server.s_in_size);
	if (client_fd != -1)
			add_client(info,
				client_fd);
	else
		exit(84);
}

static void	launch_client(info_t *info)
{
	client_t	*tmp;

	if (FD_ISSET(3, &info->readfds))
		get_client(info);
	for (tmp = info->clients; tmp;
		tmp = tmp->next) {
		if (FD_ISSET(tmp->fd, &info->readfds))
			printf("isset %i\n", tmp->fd);
	}
}

static int	get_max_fd(client_t *clients)
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

int handle_clients(info_t *info)
{
	client_t	*tmp;

	FD_ZERO(&info->readfds);
	FD_SET(3, &info->readfds);
	for (tmp = info->clients;
		tmp; tmp = tmp->next)
		FD_SET(tmp->fd, &info->readfds);
	if (select(get_max_fd(info->clients),
		&info->readfds, NULL, NULL, NULL) == -1) {
			printf("error\n");
			exit(84);
		}
	else
		launch_client(info);
	return (0);
}