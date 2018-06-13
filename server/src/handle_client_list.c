/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle client list with add and delete client
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"

static void init_client(info_t *info)
{
	info->clients->id = info->id;
	info->clients->is_gui = false;
	info->clients->is_connected = true;
	info->clients->player.level = 3;
	info->clients->player.posx = rand() % info->width;
	info->clients->player.posy = rand() % info->height;
	info->clients->player.orientation = rand() % 4 + 1;
	info->clients->player.team = NULL;
	for (int i = 0; i < 7; i++)
		info->clients->ressources[i] = 0;
	info->id++;
}

void add_client(info_t *info, int fd)
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
	init_client(info);
}

void	del_elem_from_list(info_t *info, client_t *client)
{
	close(client->fd);
	if (info->clients == client) {
		info->clients = client->next;
	} else {
		client->prev->next = client->next;
	}
	free(client);
}