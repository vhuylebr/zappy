/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** look cmd
*/

#include <stdio.h>
#include "server.h"

static void oriented_north(info_t *info, client_t *client, int level)
{
    tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);
    tile_t  *tmp;

    dprintf(client->fd, "orientation nord\n");
    for (int i = 1; i <= level; i++) {
        tmp = pos;
        for (int s = 0; s < i; s++) {
            tmp = tmp->up;
            tmp = tmp->left;
        }
        for (int s = 0; s < (i * 2 + 1); s++) {
            dprintf(client->fd, "[%d, %d] ", tmp->x, tmp->y);
            tmp = tmp->right;
        }
        dprintf(client->fd, "\n");
    }
}

static void oriented_east(info_t *info, client_t *client, int level)
{
    tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);
    tile_t  *tmp;

    dprintf(client->fd, "orientation est\n");
    for (int i = 1; i <= level; i++) {
        tmp = pos;
        for (int s = 0; s < i; s++) {
            tmp = tmp->right;
            tmp = tmp->up;
        }
        for (int s = 0; s < (i * 2 + 1); s++) {
            dprintf(client->fd, "[%d, %d] ", tmp->x, tmp->y);
            tmp = tmp->down;
        }
        dprintf(client->fd, "\n");
    }
}

static void oriented_south(info_t *info, client_t *client, int level)
{
    tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);
    tile_t  *tmp;

    dprintf(client->fd, "orientation sud\n");
    for (int i = 1; i <= level; i++) {
        tmp = pos;
        for (int s = 0; s < i; s++) {
            tmp = tmp->down;
            tmp = tmp->right;
        }
        for (int s = 0; s < (i * 2 + 1); s++) {
            dprintf(client->fd, "[%d, %d] ", tmp->x, tmp->y);
            tmp = tmp->left;
        }
        dprintf(client->fd, "\n");
    }
}

static void oriented_west(info_t *info, client_t *client, int level)
{
    tile_t  *pos = get_tile(client->player.posx, client->player.posy, info);
    tile_t  *tmp;

    dprintf(client->fd, "orientation ouest\n");
    for (int i = 1; i <= level; i++) {
        tmp = pos;
        for (int s = 0; s < i; s++) {
            tmp = tmp->left;
            tmp = tmp->down;
        }
        for (int s = 0; s < (i * 2 + 1); s++) {
            dprintf(client->fd, "[%d, %d] ", tmp->x, tmp->y);
            tmp = tmp->up;
        }
        dprintf(client->fd, "\n");
    }
}

void    look(info_t *info, client_t *client, char **cmd)
{
    int level = client->player.level;

    (void)cmd;
    dprintf(client->fd, "my pos = %d %d\n", client->player.posx, client->player.posy);
    if (client->player.orientation == 1)
        oriented_north(info, client, level);
    else if (client->player.orientation == 2)
        oriented_east(info, client, level);
    else if (client->player.orientation == 3)
        oriented_south(info, client, level);
    else
        oriented_west(info, client, level);
}