/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle team name and reuse a disconnect player
*/

#include <stdio.h>
#include <string.h>
#include "server.h"

static void display_begin(info_t *info, client_t *client, int c_num)
{
	dprintf(client->fd, "%d\n%d %d\n", c_num - 1,
		info->width, info->height);
}

static int handle_reuse(info_t *info, client_t *client, int c_num, char *name)
{
	for (client_t *tmp = info->clients; tmp; tmp = tmp->next) {
		if (tmp->player.team && !strcmp(tmp->player.team, name)
			&& tmp->is_connected == false) {
				tmp->fd = client->fd;
				tmp->is_connected = true;
				del_elem_from_list(info, client);
				display_begin(info, tmp, c_num);
				return (0);
		}
	}
	return (1);
}

static void init_gui(client_t *client, char *name)
{
	client->is_gui = true;
	client->player.team = strdup(name);
	client->player.posx = -1;
	client->player.posx = -1;
	client->is_connected = true;
	client->is_set = false;
}

void	team_name(info_t *info, client_t *client, char *name)
{
	int	c_num;

	if (!strcmp("GUI", name)) {
		init_gui(client, name);
		display_begin(info, client, 0);
		return ;
	}
	c_num = get_cli_num(info->clients, name, info->nb_cli);
	if (c_num <= 0) {
		dprintf(client->fd, "ko\n");
		return;
	}
	if (handle_reuse(info, client, c_num, name) == 1) {
		for (int i = 0; info->name[i]; i++) {
			if (!strcmp(info->name[i], name)) {
				client->player.team = strdup(name);
				init_client(info, client);
				display_begin(info, client, c_num);
				return ;
			}
		}
		dprintf(client->fd, "ko\n");
	}
}
