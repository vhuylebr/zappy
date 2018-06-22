/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** inittialization of the random map
*/

#include <stdlib.h>
#include <stdio.h>
#include "server.h"

static const char *tab_ressources[7] = {
	"food",
	"linemate",
	"deraumere",
	"sibur",
	"mendiane",
	"phiras",
	"thystame"
};

int	display_inventory_tile(tile_t *tile, int fd)
{
	int	nb_player = get_client_tile_size(tile);
	int	empty = 0;

	for (int i = 0; i < nb_player; i++)
		dprintf(fd, "player ");
	for (int i = 0; i < 7; ++i) {
		if (tile->ressources[i]) {
			for (int y = tile->ressources[i]; y > 0; --y) {
				dprintf(fd, "%s ", tab_ressources[i]);
				empty = 1;
			}
		}
	}
	return ((empty == 0 && nb_player == 0) ? 1 : 0);
}

static tile_t	*init_tile(int x, int y)
{
	tile_t	*tile = malloc(sizeof(tile_t));
	tile->x = x;
	tile->y = y;
	tile->clients_list = NULL;
	tile->ressources[FOOD] = (rand() % PROB) == 0 ? (rand() % 3 + 1) : 0;
	tile->ressources[LINEMATE] = (rand() % PROB) == 0 ? (rand() % 3 + 1) : 0;
	tile->ressources[DERAUMERE] = (rand() % PROB) == 0 ? (rand() % 3 + 1) : 0;
	tile->ressources[SIBUR] = (rand() % PROB) == 0 ? (rand() % 3 + 1) : 0;
	tile->ressources[MENDIANE] = (rand() % PROB) == 0 ? (rand() % 3 + 1) : 0;
	tile->ressources[PHIRAS] = (rand() % PROB) == 0 ? (rand() % 3 + 1) : 0;
	tile->ressources[THYSTAME] = (rand() % PROB) == 0 ? (rand() % 3 + 1) : 0;
	return (tile);
}

static void	set_width_loop(info_t *info, tile_t	*map)
{
	tile_t	*tmpy = map;
	tile_t	*tmpx = NULL;
	int x = 0;

	for (int y = 0; y < info->height; ++y, tmpy = tmpy->down) {
		tmpx = tmpy;
		for (x = 0; x + 1 < info->width; ++x, tmpx = tmpx->right) {
			tmpx->right = init_tile(x + 1, y);
			tmpx->right->left = tmpx;
		}
		tmpx->right = tmpy;
		tmpy->left = tmpx;
		if (y + 1 < info->height) {
			tmpy->down = init_tile(0, y + 1);
			tmpy->down->up = tmpy;
		} else {
			tmpy->down = map;
			tmpy->down->up = tmpy;
		}
	}
}

static void	set_height_loop(info_t *info, tile_t *map)
{
	tile_t	*tmpx = map;
	tile_t	*tmpy = map->down;

	for (int y = 0; y < info->height; ++y, tmpx = tmpx->down, tmpy = tmpy->down) {
		for (int x = 0; x < info->width; ++x, tmpx = tmpx->right,
			tmpy = tmpy->right) {
			tmpx->down = tmpy;
			tmpy->up = tmpx;
		}
	}
}

void	init_map(info_t *info)
{
	tile_t	*map = init_tile(0, 0);

	set_width_loop(info, map);
	set_height_loop(info, map);
	info->map = map;
}