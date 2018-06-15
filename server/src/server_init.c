/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server_init
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "server.h"

static int bind_server(server_t *server)
{
	if (bind(server->fd, (const struct sockaddr *)&server->s_in,
		sizeof(server->s_in)) == -1) {
		printf("Error: bind failed\n");
		if (close(server->fd) == -1)
			my_perror("Error: close failed\n", 84);
		return (84);
	}
	if (listen(server->fd, 42) == -1) {
		printf("Error: listen failed\n");
		if (close(server->fd) == -1)
			my_perror("Error: close failed\n", 84);
		return (84);
	}
	return (0);
}

int init_serveur(int port, server_t *server)
{
	server->s_in_size = sizeof(server->s_in_client);
	server->pe = getprotobyname("TCP");
	if (!server->pe)
		my_perror("Error getprotobyname failed\n", 84);
	server->fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto);
	if (server->fd == -1)
		my_perror("Error: fd failed\n", 84);
	server->s_in.sin_family = AF_INET;
	server->s_in.sin_port = htons(port);
	server->s_in.sin_addr.s_addr = INADDR_ANY;
	if (bind_server(server))
		return (84);
	return (0);
}