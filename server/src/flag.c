/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** flag function 1
*/

#include "server.h"

int	flag_p(char **av, int i, info_t *info)
{
        return (flag_cmd(av, i, &info->port));
}

int	flag_x(char **av, int i, info_t *info)
{
        return (flag_cmd(av, i, &info->width));
}

int	flag_y(char **av, int i, info_t *info)
{
        return (flag_cmd(av, i, &info->height));
}

int	flag_c(char **av, int i, info_t *info)
{
        return (flag_cmd(av, i, &info->nb_cli));
}

int	flag_f(char **av, int i, info_t *info)
{
        return (flag_cmd(av, i, &info->freq));
}
