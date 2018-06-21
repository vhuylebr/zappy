/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fork cmd
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

static	void add_disconnect_player(info_t *info, char *team, int posx, int posy)
{
	info->clients->id = info->id;
	info->clients->is_gui = false;
	info->clients->is_set = false;
	info->clients->is_connected = false;
	info->clients->player.level = 1;
	info->clients->player.team = strdup(team);
	info->clients->player.posx = posx;
	info->clients->player.posy = posy;
	info->clients->player.orientation = rand() % 4 + 1;
	for (int i = 0; i < 7; i++)
		info->clients->ressources[i] = 0;
	info->clients->ressources[FOOD] = 10;
	add_client_to_tile(get_tile(posx, posy, info), info->clients);
	info->id++;
	for (gui_list_t *tmp = info->gui; tmp; tmp = tmp->next) {
		if (tmp->gui->is_log)
			dprintf(tmp->gui->fd ,"np %i %i %i %i %i %i %i %i %i %i %s\n",
				info->clients->id, info->clients->player.posx,
				info->clients->player.posy,
				info->clients->ressources[0], info->clients->ressources[1],
				info->clients->ressources[2], info->clients->ressources[3],
				info->clients->ressources[4], info->clients->ressources[5],
				info->clients->ressources[6], info->clients->player.team);
	}
}

void	fork_player(info_t *info, client_t *client, char **cmd)
{
	(void)cmd;
	team_t	*client_team = get_team(info->team, client->player.team);
	
	client_team->nb_cli++;
	add_client(info, -1);
	add_disconnect_player(info, client->player.team, client->player.posx,
		client->player.posy);
	dprintf(client->fd, "ok\n");
}