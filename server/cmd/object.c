/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** object cmd
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

static void player_took_object(tile_t *tile, client_t *client, int type)
{
	if (tile->ressources[type] <= 0) {
		dprintf(client->fd, "ko\n");
		return ;
	}
	tile->ressources[type] -= 1;
	client->ressources[type] += 1;
	dprintf(client->fd, "ok\n");
}

void    take(info_t *info, client_t *client, char **cmd)
{
	char    *stuff[7] = {"food", "linemate", "deraumere", "sibur",
							"mendiane", "phiras", "thystame"};
	
	if (!cmd[1]) {
		dprintf(client->fd, "ko\n");
		return ;
	}
	for (int i = 0; i < 7; i++) {
		if (!strcasecmp(stuff[i], cmd[1])) {
			player_took_object(get_tile(client->player.posx,
										client->player.posy, info), client, i);
			return ;
		}
	}
	dprintf(client->fd, "ko\n");
}

static void player_set_object(tile_t *tile, client_t *client, int type)
{
	if (client->ressources[type] <= 0) {
		dprintf(client->fd, "ko\n");
		return ;
	}
	tile->ressources[type] += 1;
	client->ressources[type] -= 1;
	dprintf(client->fd, "ok\n");
}

void    set(info_t *info, client_t *client, char **cmd)
{
	char    *stuff[7] = {"food", "linemate", "deraumere", "sibur",
							"mendiane", "phiras", "thystame"};

	if (!cmd[1]) {
		dprintf(client->fd, "ko\n");
		return ;
	}
	for (int i = 0; i < 7; i++) {
		if (!strcasecmp(stuff[i], cmd[1])) {
			player_set_object(get_tile(client->player.posx,
										client->player.posy, info), client, i);
			return ;
		}
	}
	dprintf(client->fd, "ko\n");
}