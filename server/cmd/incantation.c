/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** incantation cmd
*/

#include <stdio.h>
#include "server.h"

incantation_t   incantation_table[7] = 
{
    {1, 1, 1, 0, 0, 0, 0, 0},
    {2, 2, 1, 1, 1, 0, 0, 0},
    {3, 2, 2, 0, 1, 0, 2, 0},
    {4, 4, 1, 1, 2, 0, 1, 0},
    {5, 4, 1, 2, 1, 3, 0, 0},
    {6, 6, 1, 2, 3, 0, 1, 0},
    {7, 6, 2, 2, 2, 2, 2, 1}
};

static int  verif_ressources(incantation_t condition, client_t *client)
{
    int ressources[7] = {-1, condition.linemate, condition.deraumere,
                        condition.sibur, condition.mendiane, condition.phiras,
                        condition.thystame};

    for (int i = 1; i < 7; i++) {
        if (client->ressources[i] < ressources[i]) {
            dprintf(client->fd, "ko\n");
            return (-1);
        }
    }
    return (0);
}

static void start_incantation(client_t *client, incantation_t condition)
{
    dprintf(client->fd, "Elevation underway\n");
    client->ressources[LINEMATE] -= condition.linemate;
    client->ressources[DERAUMERE] -= condition.deraumere;
    client->ressources[SIBUR] -= condition.sibur;
    client->ressources[MENDIANE] -= condition.mendiane;
    client->ressources[PHIRAS] -= condition.phiras;
    client->ressources[THYSTAME] -= condition.thystame;
    client->player.level += 1;
    dprintf(client->fd, "Current level: %d\n", client->player.level);
}

void    incantation(info_t *info, client_t *client, char **cmd)
{
    incantation_t   condition = incantation_table[client->player.level - 1];
    tile_t          *player_pos = get_tile(client->player.posx,
                                            client->player.posy, info);
    int             nb_player = 0;

    (void)cmd;
    for (client_list_t *tmp = player_pos->clients_list; tmp; tmp = tmp->next) {
        if (tmp->client->player.level == client->player.level)
            nb_player += 1;
    }
    if (nb_player < condition.nb_player) {
        dprintf(client->fd, "ko\n");
        return ;
    }
    if (verif_ressources(condition, client) == -1)
        return ;
    start_incantation(client, condition);
}