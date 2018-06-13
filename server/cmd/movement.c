/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** movement cmd
*/

#include <stdio.h>
#include "server.h"

void    forward(info_t *info, client_t *client, char **cmd)
{
    tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);

    (void)cmd;
    del_client_from_tile(pos, client);
    if (client->player.orientation == UP)
        add_client_to_tile(pos->up, client);
    else if (client->player.orientation == RIGHT)
        add_client_to_tile(pos->right, client);
    else if (client->player.orientation == DOWN)
        add_client_to_tile(pos->down, client);
    else if (client->player.orientation == LEFT)
        add_client_to_tile(pos->left, client);
    dprintf(client->fd, "ok\n");
}

void    right(info_t *info, client_t *client, char **cmd)
{
    (void)info;
    (void)cmd;
    client->player.orientation += 1;
    if (client->player.orientation >= 5)
        client->player.orientation = 1;
    dprintf(client->fd, "ok\n");
}

void    left(info_t *info, client_t *client, char **cmd)
{
    (void)info;
    (void)cmd;
    client->player.orientation -= 1;
    if (client->player.orientation <= 0)
        client->player.orientation = 4;
    dprintf(client->fd, "ok\n");
}

void    inventory(info_t *info, client_t *client, char **cmd)
{
    char    *item[7] = {"food", "linemate", "deraumere",
                        "sibur", "mendiane", "phiras", "thystame"};

    (void)info;
    (void)cmd;
    dprintf(client->fd, "[");
    for (int i = 0; i < 7; i++) {
        dprintf(client->fd, "%s %d", item[i], client->ressources[i]);
        if (i != 6)
            dprintf(client->fd, ", ");
    }
    dprintf(client->fd, "]\n");
}