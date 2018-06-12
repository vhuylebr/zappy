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

static int	handle_client(info_t *info, client_t *client)
{
	char		**cmds = NULL;
	char		*buff = NULL;

	printf("handle client");
	if (get_next_line(client->fd, &buff) == 0 || buff == NULL) {
		del_elem_from_list(info, client);
		return (0);
	}
	cmds = my_str_to_wordtab(buff, ' ');
	if (cmds == NULL || !cmds[0])
		return (-1);
	check_function(info, client, cmds);
	free_tab(cmds);
	return(0);
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
	dprintf(client_fd, "Welcome\n");
}

static void	launch_client(info_t *info)
{
	for (client_t *tmp = info->clients; tmp;
		tmp = tmp->next) {
		if (FD_ISSET(tmp->fd, &info->readfds))
			handle_client(info, tmp);
	}
	if (FD_ISSET(3, &info->readfds))
		get_client(info);
}

int handle_clients(info_t *info)
{
	FD_ZERO(&info->readfds);
	FD_SET(3, &info->readfds);
	for (client_t *tmp = info->clients;
		tmp; tmp = tmp->next)
			FD_SET(tmp->fd, &info->readfds);
	if (select(get_max_fd(info->clients),
		&info->readfds, NULL, NULL, NULL) == -1) {
			perror("");
			exit(84);
		}
	else
		launch_client(info);
	return (0);
}