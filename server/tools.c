/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** server tools
*/

#include <stdio.h>

int	check_is_number(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	}
	return (0);
}

int	my_perror(char *str, int ret)
{
	dprintf(2, "%s\n", str);
	return (ret);
}
