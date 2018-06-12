/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look cmd
*/

#include <stdio.h>
#include "server.h"

void    look(info_t *info, client_t *client, char **cmd)
{
    (void)info;(void)client;(void)cmd;
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