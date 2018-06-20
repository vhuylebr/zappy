/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle client list with add and delete client
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "server.h"

void init_client(info_t *info, client_t *client)
{
	int	posx = rand() % info->width;
	int	posy = rand() % info->height;

	client->id = info->id;
	client->is_gui = false;
	client->is_set = false;
	client->is_connected = true;
	client->player.level = 1;
	client->player.posx = posx;
	client->player.posy = posy;
	client->player.orientation = rand() % 4 + 1;
	for (int i = 0; i < 7; i++)
		client->ressources[i] = 0;
	client->ressources[FOOD] = 10;
	add_client_to_tile(get_tile(posx, posy, info), info->clients);
	info->id++;
	for (gui_list_t *tmp = info->gui; tmp; tmp = tmp->next) {
		dprintf(tmp->gui->fd ,"np %i %i %i\n", client->id, client->player.posx,
			client->player.posy);
	}
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
	for (int i = 0; i < 10; i++)
		info->clients->buff[i] = NULL;
	info->clients->fd = fd;
	info->clients->wait_time = -1;
	info->clients->food_time = time(NULL);
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
	// free(client);
}