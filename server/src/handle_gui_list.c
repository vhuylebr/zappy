/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** handle gui list
*/

#include <stdlib.h>
#include "server.h"

void	add_client_gui(info_t *info, client_t *gui)
{
	gui_list_t *node = malloc(sizeof(gui_list_t));

	node->gui = gui;
	if (info->gui == NULL) {
		info->gui = node;
		info->gui->next = NULL;
	} else {
		node->next = info->gui;
		info->gui = node;
	}
}

void	remove_client_gui(info_t *info, client_t *gui)
{
	gui_list_t	*tmp = NULL;

	if (info->gui->gui == gui) {
		info->gui = info->gui->next;
	} else {
		for (tmp = info->gui; tmp->next->gui != gui;
			tmp = tmp->next);
		tmp->next = tmp->next->next;
		// free(tmp->next)
	}
	del_elem_from_list(info, gui);
}
