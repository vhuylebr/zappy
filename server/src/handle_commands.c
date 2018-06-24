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

static void	player_die(info_t *info, client_t *client)
{
	del_elem_from_list(info, client);
	dprintf(client->fd, "dead\n");
	close(client->fd);
	for (gui_list_t *tmp = info->gui; tmp; tmp = tmp->next) {
		if (tmp->gui->is_log)
			dprintf(tmp->gui->fd ,"dp %i\n",
				client->id);
	}
}

static int	food_handling(info_t *info, client_t *client)
{
	time_t now = time(NULL);

	if (now - client->food_time >= 126 / info->freq) {
		if (client->ressources[FOOD] <= 0) {
			dprintf(client->fd, "dead\n");
			player_die(info, client);
			return (-1);
		}
		client->ressources[FOOD] -= 1;
		dprintf(client->fd, "Je perds une food : %d\n", client->ressources[FOOD]);
		client->food_time = now;
	}
	return (0);
}

void	check_function(info_t *info, client_t *client)
{
	if (client->is_gui == true || client->player.team == NULL)
		return ;
	if (food_handling(info, client) == -1)
		return ;
	if (client->wait_time == -1 && client->buff[0])
		handle_new_cmd(client);
	else if (client->wait_time != -1)
		wait_for_exec(info, client);
}