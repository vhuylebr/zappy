/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** tools2
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

team_t *get_team(team_t **team, char *name)
{
	for (int i = 0; team[i]; i++) {
		if (!strcmp(team[i]->name, name))
			return (team[i]);
	}
	return (NULL);
}

tile_t  *get_tile(int x, int y, info_t *info)
{
	tile_t  *tmp = info->map;

	for (int i = 0; i < x; i++)
		tmp = tmp->right;
	for (int i = 0; i < y; i++)
		tmp = tmp->down;
	return (tmp);
}

void	remove_buff(char *buff[10])
{
	char	*first = buff[0];

	for (int i = 0; buff[i] && i < 10; i++)
		buff[i] = buff[i + 1];
	free(first);
}