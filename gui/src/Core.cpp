/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** core cpp
*/

#include "Core.hpp"

Core::Core()
{
    Socket newsocket("TCP");

    newsocket.connection(4242);
}

Core::~Core()
{
}

void Core::loop()
{
	while (1)
		std::cout << "loop on" << std::endl;
}