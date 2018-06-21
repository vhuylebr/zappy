/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle login of player
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"

static void display_info_for_gui(info_t *info)
{
	int y = 0;
	int x = 0;

	for (tile_t	*tmp = info->map; y < info->height;
		++y, tmp = tmp->down) {
		tile_t	*tmp2 = tmp;
		for (x = 0; x < info->width; ++x, tmp2 = tmp2->right) {
			for (gui_list_t *tmpgui = info->gui; tmpgui; tmpgui = tmpgui->next) {
				dprintf(tmpgui->gui->fd ,"nt %i %i %i %i %i %i %i %i %i\n",
					tmp2->x, tmp2->y, tmp2->ressources[0], tmp2->ressources[1],
					tmp2->ressources[2], tmp2->ressources[3],
					tmp2->ressources[4], tmp2->ressources[5],
					tmp2->ressources[6]);
			}
		}
	}
	for (gui_list_t *tmpgui = info->gui; tmpgui; tmpgui = tmpgui->next) {
		for (client_t *tmp = info->clients; tmp; tmp = tmp->next) {
			if (tmp->is_gui == false)
				dprintf(tmpgui->gui->fd ,"np %i %i %i %i %i %i %i %i %i %i %s\n",
					tmp->id, tmp->player.posx, tmp->player.posy,
					tmp->ressources[0], tmp->ressources[1],
					tmp->ressources[2], tmp->ressources[3],
					tmp->ressources[4], tmp->ressources[5],
					tmp->ressources[6], tmp->player.team);
		}
	}
}

void login(info_t *info, client_t *client, char **cmd)
{
	if (!cmd[1]) {
		dprintf(client->fd, "401\n");
		return;
	}
	(void)info;
	if (client->user_name)
		free(client->user_name);
	client->user_name = strdup(cmd[1]);
}


void pass(info_t *info, client_t *client, char **cmd)
{
	if (!cmd[1]) {
		dprintf(client->fd, "401\n");
		return;
	}
	if (!strcmp(client->user_name, "toto") && !strcmp(cmd[1], "tata")) {
		client->is_admin = true;
		dprintf(client->fd, "200\n");
		dprintf(client->fd, "msz %i %i\n", info->width, info->height);
	} else if (!strcmp(client->user_name, "guest") && !strcmp(cmd[1], "guest")) {
		dprintf(client->fd, "200\n");
		dprintf(client->fd, "msz %i %i\n", info->width, info->height);
	} else {
		if (client->user_name)
			free(client->user_name);
		client->user_name = NULL;
		dprintf(client->fd, "401\n");
		return;
	}
	client->is_log = true;
	display_info_for_gui(info);
}