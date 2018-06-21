/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** movement cmd
*/

#include <stdio.h>
#include "server.h"

void    forward(info_t *info, client_t *client, char **cmd)
{
	tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);

	(void)cmd;
	if (client->player.orientation == UP)
		add_client_to_tile(pos->up, client);
	else if (client->player.orientation == RIGHT)
		add_client_to_tile(pos->right, client);
	else if (client->player.orientation == DOWN)
		add_client_to_tile(pos->down, client);
	else if (client->player.orientation == LEFT)
		add_client_to_tile(pos->left, client);
	del_client_from_tile(pos, client);
	for (gui_list_t *tmp = info->gui; tmp; tmp = tmp->next) {
		if (tmp->gui->is_log)
			dprintf(tmp->gui->fd ,"mop %i %i %i %i\n", client->id,
			client->player.posx, client->player.posy, client->player.orientation);
	}
	dprintf(client->fd, "ok\n");
}

void    right(info_t *info, client_t *client, char **cmd)
{
	(void)info;
	(void)cmd;
	client->player.orientation += 1;
	if (client->player.orientation >= 5)
		client->player.orientation = 1;
	dprintf(client->fd, "ok\n");
	for (gui_list_t *tmp = info->gui; tmp; tmp = tmp->next) {
		if (tmp->gui->is_log)
			dprintf(tmp->gui->fd ,"mop %i %i %i %i\n", client->id, client->player.posx,
				client->player.posy, client->player.orientation);
	}
}

void    left(info_t *info, client_t *client, char **cmd)
{
	(void)info;
	(void)cmd;
	client->player.orientation -= 1;
	if (client->player.orientation <= 0)
		client->player.orientation = 4;
	dprintf(client->fd, "ok\n");
	for (gui_list_t *tmp = info->gui; tmp; tmp = tmp->next) {
		if (tmp->gui->is_log)
			dprintf(tmp->gui->fd ,"mop %i %i %i %i\n", client->id,
				client->player.posx, client->player.posy,
					client->player.orientation);
	}
}

void    inventory(info_t *info, client_t *client, char **cmd)
{
	char    *item[7] = {"food", "linemate", "deraumere",
						"sibur", "mendiane", "phiras", "thystame"};

	(void)info;
	(void)cmd;
	dprintf(client->fd, "[");
	for (int i = 0; i < 7; i++) {
		dprintf(client->fd, "%s %d", item[i], client->ressources[i]);
		if (i != 6)
			dprintf(client->fd, ", ");
	}
	dprintf(client->fd, "]\n");
}