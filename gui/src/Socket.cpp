/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** socket file
*/

#include "Socket.hpp"

Socket::Socket(std::string type)
{
	struct protoent		*proto;

	proto = getprotobyname(type.c_str());
	if (!proto)
			return ;
	_guiFd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (_guiFd == -1)
			return ;
	return ;
}

Socket::~Socket()
{
	close(_guiFd);
}

void    Socket::connection(int port)
{
	struct sockaddr_in	s_in;

	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr = INADDR_ANY;
	if (connect(_guiFd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
		std::cout << "error" << std::endl;
	return ;
}