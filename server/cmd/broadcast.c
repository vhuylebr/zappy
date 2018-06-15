/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast cmd
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

static const	coord_t dirs[] = {
	{0, 0},
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1},
	{-1, 0},
	{-1, 1}
};

static int	find_dir(coord_t vec, int orientation)
{
	vec.x = vec.x ? vec.x / abs(vec.x) : vec.x;
	vec.y = vec.y ? vec.y / abs(vec.y) : vec.y;
	for (int i = 0 ; i < 9 ; i += 1) {
		if (dirs[i].x == vec.x && dirs[i].y == vec.y) {
			if (!i)
				return (0);
			i = i - 2 * orientation;
			i += i < 0 ? 8 : 0;
			i -= i >= 8 ? 8 : 0;
			return (i);
		}
	}
	return (0);
}

static void	send_msg(client_t *dest, char **cmd, coord_t vec)
{
	int	dir = find_dir(vec, (int)dest->player.orientation - 1);

	dprintf(dest->fd, "message %d,", dir);
	for (int i = 1 ; cmd[i] != NULL ; i += 1) {
		dprintf(dest->fd, " %s", cmd[i]);
	}
	dprintf(dest->fd, "\n");
}

void	broadcast(info_t *info, client_t *client, char **cmd)
{
	coord_t	offset = {info->width / 2 - client->player.posx,
		info->height / 2 - client->player.posy};
	coord_t	pos;
	coord_t	vector;

	for (client_t *tmp = info->clients ; tmp != NULL ; tmp = tmp->next) {
		if (tmp == client)
			continue;
		pos.x = (tmp->player.posx + offset.x) % info->width;
		pos.y = (tmp->player.posy + offset.y) % info->height;
		if (pos.x < 0)
			pos.x += info->width;
		if (pos.y < 0)
			pos.y += info->height;
		vector.x = pos.x + info->width / 2;
		vector.y = pos.y + info->height / 2;
		send_msg(tmp, cmd, vector);
	}
}

void    connect_nbr(info_t *info, client_t *client, char **cmd)
{
    (void)cmd;
    dprintf(client->fd, "%d\n",
            get_team(info->team, client->player.team)->nb_cli);
}