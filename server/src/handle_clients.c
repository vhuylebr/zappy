/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle clients
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "server.h"
#include "get_next_line.h"

static void add_client(info_t *info, int fd)
{
	client_t *tmp = malloc(sizeof(client_t));

	if (info->clients == NULL) {
		info->clients = tmp;
		info->clients->next = NULL;
		info->clients->prev = NULL;
	} else {
		info->clients->prev = tmp;
		tmp->next = info->clients;
		tmp->prev = NULL;
		info->clients = tmp;
	}
	info->clients->fd = fd;
}


void	del_elem_from_list(info_t *info, client_t *client)
{
	write(1, "delete\n", 7);
	close(client->fd);
	if (info->clients == client)
		info->clients = client->next;
	else
		client->prev->next = client->next;
	free(client);
}

static int	handle_client(info_t *info, client_t *client)
{
	char		**cmds = NULL;
	char		*buff = NULL;

	if (get_next_line(client->fd, &buff) == 0 || buff == NULL) {
		del_elem_from_list(info, client);
		return (0);
	}
	write(1, buff, strlen(buff));
	write(1, "\n", 1);
	cmds = my_str_to_wordtab(buff, ' ');
	if (cmds == NULL || !cmds[0])
		return (-1);
	return (0);
	// return (check_function(fd, cli, cmds, chann));
}

void	get_client(info_t *info)
{
	int client_fd = accept(info->server.fd,
		(struct sockaddr *)&info->server.s_in_client,
			&info->server.s_in_size);
	write(1, "getClient\n", 10);
	if (client_fd != -1)
			add_client(info,
				client_fd);
	else
		exit(84);
}

static void	launch_client(info_t *info)
{
	if (FD_ISSET(3, &info->readfds))
		get_client(info);
	if (info->clients)
		for (client_t *tmp = info->clients; tmp;
			tmp = tmp->next) {
			if (FD_ISSET(tmp->fd, &info->readfds))
				handle_client(info, tmp);
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
	FD_ZERO(&info->readfds);
	FD_SET(3, &info->readfds);
	for (client_t *tmp = info->clients;
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