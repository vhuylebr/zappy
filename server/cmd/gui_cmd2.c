/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** gui cmd 2
*/

#include <stdio.h>
#include <stdlib.h>
#include "server.h"

void    plv(info_t *info, client_t *client, char **cmd)
{
    int id = atoi(cmd[1]);

    for (client_t *tmp = info->clients; tmp; tmp = tmp->next) {
        if (tmp->id == id)
            dprintf(client->fd, "plv %d %d\n", id, tmp->player.level);
    }
}

void    pin(info_t *info, client_t *client, char **cmd)
{
    (void)info;(void)client;(void)cmd;
}

void    sgt(info_t *info, client_t *client, char **cmd)
{
    (void)info;(void)client;(void)cmd;
}

void    sst(info_t *info, client_t *client, char **cmd)
{
    (void)info;(void)client;(void)cmd;
}