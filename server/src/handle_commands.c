/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle command
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include "server.h"

cmd_t	ia_cmd[IA_CMD_SIZE] =
{
	{"Forward", &forward, 7},
	{"Right", &right, 7},
	{"Left", &left, 7},
	{"Look", &look, 7},
	{"Inventory", &inventory, 1},
	{"Broadcast", &broadcast, 7},
	{"Connect_nbr", &connect_nbr, 0},
	{"Fork", &fork_player, 42},
	{"Eject", &eject, 7},
	{"Take", &take, 7},
	{"Set", &set, 7},
	{"Incantation", &incantation, 300}
};

static void	handle_new_cmd(client_t *client)
{
	int		find = 0;
	char	**cmd = my_str_to_wordtab(client->buff[0], ' ');

	if (cmd == NULL)
		exit(0);
	for (int i = 0; i < IA_CMD_SIZE; i++) {
		if (!strcasecmp(ia_cmd[i].cmd, cmd[0])) {
			client->func = ia_cmd[i].func;
			client->wait_time = ia_cmd[i].freq;
			client->time = time(NULL);
			find = 1;
		}
	}
	if (find == 0) {
		dprintf(client->fd, "ko\n");
		remove_buff(client->buff);
	}
	free_tab(cmd);
}

static void	wait_for_exec(info_t *info, client_t *client)
{
	char	**cmd;
	time_t	current = time(NULL);

	if (current - client->time >= (client->wait_time / info->freq)) {
		cmd = my_str_to_wordtab(client->buff[0], ' ');
		if (cmd == NULL)
			exit(0);
		client->func(info, client, cmd);
		client->wait_time = -1;
		remove_buff(client->buff);
		free_tab(cmd);
	}
}

void	check_function(info_t *info, client_t *client)
{
	if (client->is_gui == true || client->buff[0] == NULL
	|| client->player.team == NULL)
		return ;
	if (client->wait_time == -1)
		handle_new_cmd(client);
	else
		wait_for_exec(info, client);
}