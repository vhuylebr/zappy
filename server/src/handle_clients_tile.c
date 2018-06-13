/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle clients of a tile
*/

#include "server.h"

void add_client_tile(tile_t *tile, client_t *client)
{
	if (tile->clients == NULL) {
		tile->clients = client;
		tile->clients->next = NULL;
		tile->clients->prev = NULL;
	} else {
		tile->clients->prev = client;
		client->next = tile->clients;
		client->prev = NULL;
		tile->clients = client;
	}
}

void	del_elem_from_list_tile(tile_t *tile, client_t *client)
{
	if (tile->clients == client) {
		tile->clients = client->next;
	} else {
		client->prev->next = client->next;
	}
}