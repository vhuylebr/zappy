/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server tools
*/

#include <stdlib.h>
#include <stdio.h>

static int	check_is_number(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	return (0);
}

int	flag_cmd(char **av, int i, int *var)
{
	if (!av[i + 1] || check_is_number(av[i + 1]) == -1)
		return (-1);
	*var = atoi(av[i + 1]);
	return (i + 1);
}


int	my_perror(char *str, int ret)
{
	dprintf(2, "%s", str);
	return (ret);
}
