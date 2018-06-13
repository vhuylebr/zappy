/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast cmd
*/

#include <stdio.h>
#include "server.h"

void    broadcast(info_t *info, client_t *client, char **cmd)
{
    (void)info;(void)client;(void)cmd;
}

void    connect_nbr(info_t *info, client_t *client, char **cmd)
{
    (void)cmd;
    dprintf(client->fd, "%d\n",
            get_cli_num(info->clients, client->player.team, info->nb_cli));
}