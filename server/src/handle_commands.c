/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle command
*/

#include <stdio.h>
#include <strings.h>
#include "server.h"

cmd_t       ia_cmd[IA_CMD_SIZE] =
{
    {"Forward", &forward},
    {"Right", &right},
    {"Left", &left},
    {"Look", &look},
    {"Inventory", &inventory},
    {"Broadcast", &broadcast},
    {"Connect_nbr", &connect_nbr},
    {"Fork", &fork_player},
    {"Eject", &eject},
    {"Take", &take},
    {"Set", &set},
    {"Incantation", &incantation}
};

cmd_t       gui_cmd[GUI_CMD_SIZE] =
{
    {"msz", &msz},
    {"bct", &bct},
    {"mct", &mct},
    {"tna", &tna},
    {"ppo", &ppo},
    {"plv", &plv},
    {"pin", &pin},
    {"sgt", &sgt},
    {"sst", &sst}
};

tile_t  *get_tile(int x, int y, info_t *info)
{
    tile_t  *tmp = info->map;

    for (int i = 0; i < x; i++)
        tmp = tmp->right;
    for (int i = 0; i < y; i++)
        tmp = tmp->down;
    return (tmp);
}

static void gui_handling(info_t *info, client_t *client, char **cmd)
{
    int find = 0;

    for (int i = 0; i < GUI_CMD_SIZE; i++) {
        if (!strcasecmp(gui_cmd[i].cmd, cmd[0])) {
            gui_cmd[i].func(info, client, cmd);
            find = 1;
        }
    }
    if (find == 0)
        dprintf(client->fd, "ko\n");
}

static void ia_handling(info_t *info, client_t *client, char **cmd)
{
    int find = 0;

    for (int i = 0; i < IA_CMD_SIZE; i++) {
        if (!strcasecmp(ia_cmd[i].cmd, cmd[0])) {
            ia_cmd[i].func(info, client, cmd);
            find = 1;
        }
    }
    if (find == 0)
        dprintf(client->fd, "ko\n");
}

int check_function(info_t *info, client_t *client, char **cmds)
{
    printf("je suis check function\n");
    if (client->is_gui == true)
        gui_handling(info, client, cmds);
    else
        ia_handling(info, client, cmds);
    return (0);
}