/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle client list with add and delete client
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"

void init_client(info_t *info, client_t *client)
{
	client->id = info->id;
	client->is_gui = false;
	client->is_set = false;
	client->is_connected = true;
	client->player.level = 1;
	client->player.posx = rand() % info->width;
	client->player.posy = rand() % info->height;
	client->player.orientation = rand() % 4 + 1;
	for (int i = 0; i < 7; i++)
		client->ressources[i] = 0;
	client->ressources[FOOD] = 10;
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
	info->clients->is_connected = true;
	info->clients->is_gui = false;
	info->clients->is_set = false;
	info->clients->player.team = NULL;
}

void	del_elem_from_list(info_t *info, client_t *client)
{
	if (info->clients == client) {
		info->clients = client->next;
	} else {
		client->prev->next = client->next;
	}
	free(client);
}