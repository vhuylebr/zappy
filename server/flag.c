/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** flag function 1
*/

#include <stdlib.h>
#include "server.h"

int	flag_p(char **av, int i, info_t *info)
{
	if (!av[i + 1] || check_is_number(av[i + 1]) == -1)
		return (-1);
	info->port = atoi(av[i + 1]);
	return (i + 1);
}

int	flag_x(char **av, int i, info_t *info)
{
	if (!av[i + 1] || check_is_number(av[i + 1]) == -1)
		return (-1);
	info->width = atoi(av[i + 1]);
	return (i + 1);
}

int	flag_y(char **av, int i, info_t *info)
{
	if (!av[i + 1] || check_is_number(av[i + 1]) == -1)
		return (-1);
	info->height = atoi(av[i + 1]);
	return (i + 1);
}

int	flag_c(char **av, int i, info_t *info)
{
	if (!av[i + 1] || check_is_number(av[i + 1]) == -1)
		return (-1);
	info->nb_cli = atoi(av[i + 1]);
	return (i + 1);
}

int	flag_f(char **av, int i, info_t *info)
{
	if (!av[i + 1] || check_is_number(av[i + 1]) == -1)
		return (-1);
	info->freq = atoi(av[i + 1]);
	return (i + 1);
}
