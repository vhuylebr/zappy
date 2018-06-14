/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** gui cmd
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void    msz(info_t *info, client_t *client, char **cmd)
{
	(void)cmd;
	dprintf(client->fd, "msz %d %d\n", info->width, info->height);
}

void    bct(info_t *info, client_t *client, char **cmd)
{
	tile_t  *tmp = get_tile(atoi(cmd[1]), atoi(cmd[2]), info);

	dprintf(client->fd, "bct %s %s ", cmd[1], cmd[2]);
	print_ressources(tmp->ressources, client->fd);
	dprintf(client->fd, "\n");
}

void    mct(info_t *info, client_t *client, char **cmd)
{
	tile_t  *tmp = info->map;

	(void)cmd;
	for (int y = 0; y < info->height; y++) {
		for (int x = 0; x < info->width; x++) {
			dprintf(client->fd, "bct %d %d ", tmp->x, tmp->y);
			print_ressources(tmp->ressources, client->fd);
			tmp = tmp->right;
		}
		tmp = tmp->right;
		tmp = tmp->down;
	}
}

void    tna(info_t *info, client_t *client, char **cmd)
{
	(void)cmd;
	for (int i = 0; info->name[i]; i++)
		dprintf(client->fd, "%s\n", info->name[i]);
}

void    ppo(info_t *info, client_t *client, char **cmd)
{
	int id = atoi(cmd[1]);

	for (client_t *tmp = info->clients; tmp; tmp = tmp->next) {
		if (tmp->id == id)
			dprintf(client->fd, "ppo %d %d %d %d\n", id, tmp->player.posx,
			tmp->player.posy, tmp->player.orientation);
	}
}