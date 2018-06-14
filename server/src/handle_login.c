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
	if (!cmd[1])
		return;
	(void)info;
	client->user_name = strdup(cmd[1]);
}


void pass(info_t *info, client_t *client, char **cmd)
{
	if (!cmd[1])
		return;
	(void)info;
	if (!strcmp(client->user_name, "toto") && !strcmp(cmd[1], "tata")) {
		client->is_admin = true;
		dprintf(client->fd, "Hello %s\n", client->user_name);
	} else {
		if (client->user_name)
			free(client->user_name);
		client->user_name = NULL;
		dprintf(client->fd, "ERROR\n");
	}
}