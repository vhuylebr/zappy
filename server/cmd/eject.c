/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** eject cmd
*/

#include <stdio.h>
#include "server.h"

static void eject_player(tile_t *tile, int k, client_t *client)
{
    add_client_to_tile(tile, client);
    dprintf(client->fd, "eject: %d\n", k);
    client->wait_time = -1;
    remove_buff(client->buff);
}

void    eject(info_t *info, client_t *client, char **cmd)
{
    int     count = 0;
    tile_t  *tile = get_tile(client->player.posx, client->player.posy, info);
    
    (void)cmd;
    for (client_list_t *tmp = tile->clients_list; tmp; tmp = tmp->next) {
        if (tmp->client == client)
            continue;
        del_client_from_tile(tile, client);
        if (client->player.orientation == 1)
            eject_player(tile->up, 3, tmp->client);
        else if (client->player.orientation == 2)
            eject_player(tile->right, 4, tmp->client);
        else if (client->player.orientation == 3)
            eject_player(tile->down, 1, tmp->client);
        else
            eject_player(tile->left, 2, tmp->client);
        count += 1;
    }
    dprintf(client->fd, (count == 0) ? "ko\n" : "ok\n");
}