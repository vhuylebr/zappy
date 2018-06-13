/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle clients of a tile
*/

#include <stdlib.h>
#include "server.h"

void add_client_tile(tile_t *tile, client_t *client)
{
	client_list_t	*client_list_node = malloc(sizeof(client_list_t));

	client_list_node->client = client;
	if (tile->clients_list == NULL) {
		tile->clients_list = client_list_node;
		tile->clients_list->next = NULL;
	} else {
		client_list_node->next = tile->clients_list;
		tile->clients_list = client_list_node;
	}
}

void	del_elem_from_list_tile(tile_t *tile, client_t *client)
{
	client_list_t	*tmp = NULL;

	if (tile->clients_list->client == client) {
		tile->clients_list = tile->clients_list->next;
	} else {
		for (tmp = tile->clients_list; tmp->next->client != client;
			tmp = tmp->next);
		tmp->next = tmp->next->next;
	}
}