/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle clients
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "server.h"
#include "get_next_line.h"

cmd_t	gui_cmd[GUI_CMD_SIZE] =
{	
	{"login", &login, 0},
	{"pass", &pass, 0}
};

static void	add_cmd_to_buff(char *buff[10], char *cmd)
{
	int	i;

	for (i = 0; i < 10 && buff[i]; i++);
	if (i > 9)
		return;
	buff[i] = strdup(cmd);
}

static void gui_handling(info_t *info, client_t *client, char **cmd)
{
	int find = 0;

	for (int i = 0; i < GUI_CMD_SIZE; i++) {
		if (!strcasecmp(gui_cmd[i].cmd, cmd[0])) {
			gui_cmd[i].func(info, client, cmd);
			find = 1;
		}
	}
	if (find == 0)
		dprintf(client->fd, "ko\n");
}

static int	handle_client(info_t *info, client_t *client)
{
	char	*buff = NULL;
	team_t	*team;

	if (get_next_line(client->fd, &buff) <= 0 || buff == NULL) {
		close(client->fd);
		if (client->is_gui)
			remove_client_gui(info, client);
		else {
			if (client->player.team != NULL) {
				team = get_team(info->team, client->player.team);
				team->nb_cli += 1;
			}
			client->is_connected = false;
		}
		return (0);
	}
	if (client->is_gui)
		gui_handling(info, client, my_str_to_wordtab(buff, ' '));
	else if (client->player.team != NULL)
		add_cmd_to_buff(client->buff, buff);
	else
		team_name(info, client, buff);
	free(buff);
	return (0);
}

void	get_client(info_t *info)
{
	int client_fd = accept(info->server.fd,
		(struct sockaddr *)&info->server.s_in_client,
			&info->server.s_in_size);
	if (client_fd != -1)
		add_client(info, client_fd);
	else
		exit(84);
	dprintf(client_fd, "WELCOME\n");
}

static void	launch_client(info_t *info)
{
	if (FD_ISSET(3, &info->readfds))
		get_client(info);
	for (client_t *tmp = info->clients; tmp;
		tmp = tmp->next) {
		check_function(info, tmp);
		if (tmp->is_set && FD_ISSET(tmp->fd, &info->readfds)) {
			handle_client(info, tmp);
			tmp->is_set = false;
		}
	}
}

int handle_clients(info_t *info)
{
	struct timeval	tv = {1 / info->freq, 0};

	FD_ZERO(&info->readfds);
	FD_SET(3, &info->readfds);
	for (client_t *tmp = info->clients;
		tmp; tmp = tmp->next) {
			if (tmp->is_connected) {
				FD_SET(tmp->fd, &info->readfds);
				tmp->is_set = true;
			}
		}
	if (select(get_max_fd(info->clients),
		&info->readfds, NULL, NULL, &tv) == -1) {
			perror("");
			exit(84);
	} else {
		launch_client(info);
	}
	return (0);
}