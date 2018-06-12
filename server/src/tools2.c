/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** tools2
*/

#include <string.h>
#include "server.h"

int get_cli_num(client_t *cli, char *team, int nb_max)
{
    for (client_t *tmp = cli; tmp; tmp = tmp->next) {
        if (!strcmp(tmp->player.team, team) && tmp->is_connected)
            nb_max -= 1;
    }
    return (nb_max);
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
