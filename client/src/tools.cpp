//
// EPITECH PROJECT, 2018
// zappy
// File description:
// client's tool
//

#include <stdio.h>

int	my_perror(const char *str, int ret)
{
	dprintf(2, str);
	return (ret);
}
