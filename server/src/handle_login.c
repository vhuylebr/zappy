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
	}
}