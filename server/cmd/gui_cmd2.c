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
    (void)info;
    for (client_t *tmp = client; tmp && tmp->id != cmd[1]; tmp = tmp->next);
    if (!tmp) {
        dprintf(client->fd, "ko\n");
        return ;
    }
    dprintf(client->fd, "pin %d %d %d ", tmp->id, tmp->player.posx,
    tmp->player.posy);
    print_ressources(tmp->ressources, client->fd);
}

void    sgt(info_t *info, client_t *client, char **cmd)
{
    (void)info;(void)client;(void)cmd;
}

void    sst(info_t *info, client_t *client, char **cmd)
{
    (void)info;(void)client;(void)cmd;
}