/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** fill info
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

flag_t	flag_table[FLAG_SIZE] =
{
	{"-p", &flag_p},
	{"-x", &flag_x},
	{"-y", &flag_y},
	{"-n", &flag_n},
	{"-c", &flag_c},
	{"-f", &flag_f}
};

int	flag_n(char **av, int i, info_t *info)
{
	int		s;

    for (s = 1; av[s + i] && av[s + i][0] != '-'; s++) {
		for (int tmp = i + 1; av[tmp] && av[tmp][0] != '-'; tmp++) {
			if (!strcmp(av[s + i], av[tmp]) && s + i != tmp)
				return (-1);
		}
	}
	info->team = malloc(sizeof(team_t *) * (s + 1));
	if (info->team == NULL)
		return (-1);
	s = 0;
	for (i = i + 1; av[i] && av[i][0] != '-'; i++) {
		info->team[s] = malloc(sizeof(team_t));
		info->team[s]->name = av[i];
		s += 1;
	}
	info->team[s] = NULL;
	return (i - 1);
}

static void	init_value(info_t *info)
{
	info->port = 4242;
	info->width = 50;
	info->height = 50;
	info->nb_cli = 4;
	info->team = NULL;
	info->freq = 100;
}

int	fill_info(int ac, char **av, info_t *info)
{
	int	stock;

	init_value(info);
	for (int i = 1; i < ac; i++) {
		stock = i;
		for (int s = 0; s < FLAG_SIZE; s++) {
			if (!strcmp(flag_table[s].flag, av[i])) {
				i = flag_table[s].func(av, i, info);
				break ;
			}
		}
		if (stock == i)
			return (my_perror("Invalid flags\n", 84));
		else if (i == -1) {
			dprintf(2, "%s: problem with this arguments\n", av[stock]);
			return (84);
		}
	}
	return (0);
}
