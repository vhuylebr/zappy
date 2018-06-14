/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle clients of a tile
*/

#include <stdlib.h>
#include "server.h"

void add_client_to_tile(tile_t *tile, client_t *client)
{
	client_list_t	*client_list_node = malloc(sizeof(client_list_t));

	client_list_node->client = client;
	client->player.posx = tile->x;
	client->player.posy = tile->y;
	if (tile->clients_list == NULL) {
		tile->clients_list = client_list_node;
		tile->clients_list->next = NULL;
	} else {
		client_list_node->next = tile->clients_list;
		tile->clients_list = client_list_node;
	}
}

void	del_client_from_tile(tile_t *tile, client_t *client)
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

int	get_client_tile_size(tile_t *tile)
{
	int	count = 0;

	if (tile->clients_list == NULL)
		return (0);
	for (client_list_t *tmp = tile->clients_list; tmp; tmp = tmp->next)
		count += 1;
	return (count);
}