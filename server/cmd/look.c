/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look cmd
*/

#include <stdio.h>
#include "server.h"

static void oriented_north(info_t *info, client_t *client, int level)
{
	tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);
	tile_t  *tmp;

	for (int i = 1; i <= level; i++) {
		tmp = pos;
		for (int s = 0; s < i; s++) {
			tmp = tmp->up;
			tmp = tmp->left;
		}
		for (int s = 0; s < (i * 2 + 1); s++) {
			display_inventory_tile(tmp, client->fd);
			if (i != level || (s + 1) < (i * 2 + 1))
				dprintf(client->fd, ", ");
			tmp = tmp->right;
		}
	}
}

static void oriented_east(info_t *info, client_t *client, int level)
{
	tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);
	tile_t  *tmp;

	for (int i = 1; i <= level; i++) {
		tmp = pos;
		for (int s = 0; s < i; s++) {
			tmp = tmp->right;
			tmp = tmp->up;
		}
		for (int s = 0; s < (i * 2 + 1); s++) {
			display_inventory_tile(tmp, client->fd);
			if (i != level || (s + 1) < (i * 2 + 1))
				dprintf(client->fd, ", ");
			tmp = tmp->down;
		}
	}
}

static void oriented_south(info_t *info, client_t *client, int level)
{
	tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);
	tile_t  *tmp;

	for (int i = 1; i <= level; i++) {
		tmp = pos;
		for (int s = 0; s < i; s++) {
			tmp = tmp->down;
			tmp = tmp->right;
		}
		for (int s = 0; s < (i * 2 + 1); s++) {
			display_inventory_tile(tmp, client->fd);
			if (i != level || (s + 1) < (i * 2 + 1))
				dprintf(client->fd, ", ");
			tmp = tmp->left;
		}
	}
}

static void oriented_west(info_t *info, client_t *client, int level)
{
	tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);
	tile_t  *tmp;

	for (int i = 1; i <= level; i++) {
		tmp = pos;
		for (int s = 0; s < i; s++) {
			tmp = tmp->left;
			tmp = tmp->down;
		}
		for (int s = 0; s < (i * 2 + 1); s++) {
			display_inventory_tile(tmp, client->fd);
			if (i != level || (s + 1) < (i * 2 + 1))
				dprintf(client->fd, ", ");
			tmp = tmp->up;
		}
	}
}

void    look(info_t *info, client_t *client, char **cmd)
{
	int level = client->player.level;

	(void)cmd;
	dprintf(client->fd, "[");
	display_inventory_tile(get_tile(client->player.posx,
		client->player.posy, info), client->fd);
	dprintf(client->fd, ", ");
	if (client->player.orientation == 1)
		oriented_north(info, client, level);
	else if (client->player.orientation == 2)
		oriented_east(info, client, level);
	else if (client->player.orientation == 3)
		oriented_south(info, client, level);
	else
		oriented_west(info, client, level);
	dprintf(client->fd, " ]\n");
}