/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** socket's header
*/

#ifndef SOCKET_HPP_
	#define SOCKET_HPP_

# include <sys/socket.h>
# include <sys/types.h>
# include <netdb.h>
# include <iostream>
# include <unistd.h>

class Socket {
	public:
		Socket(std::string);
		~Socket();
        void    connection(int);
	private:
        void    bind();

        int _guiFd;

};

#endif /* !SOCKET_HPP_ */
