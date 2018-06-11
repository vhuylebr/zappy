/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle clients
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void	get_client(info_t *info)
{
	info->client_fd = accept(info->server.fd,
		(struct sockaddr *)&info->server.s_in_client,
			&info->server.s_in_size);
	// if (info->client_fd != -1)
	// 	info->clients_list =
	// 		add_client(info->clients_list,
	// 			info->client_fd);
}

static void	launch_client(info_t *info)
{
	client_t	*tmp;

	if (FD_ISSET(3, &info->readfds))
		get_client(info);
	for (tmp = info->clients; tmp;
		tmp = tmp->next) {
		if (FD_ISSET(tmp->fd, &info->readfds))
			printf("isset");
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

int select(int nfds, fd_set *readfds, fd_set *writefds,
           fd_set *exceptfds, struct timeval *timeout);


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