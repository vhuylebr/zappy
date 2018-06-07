/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** flag client
*/

#include <stdlib.h>
#include "client.h"

void	flag_p(char *str, client_info_t *info)
{
	if (str == NULL)
		return ;
	info->port = atoi(str);
}

void	flag_n(char *str, client_info_t *info)
{
	if (str == NULL)
		return ;
	info->name = str;
}

void	flag_h(char *str, client_info_t *info)
{
	if (str == NULL)
		return ;
	info->machine = str;
}
