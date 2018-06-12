/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** core's header
*/

#ifndef CORE_HPP_
	#define CORE_HPP_

# include <iostream>
# include "Socket.hpp"

class Core {
	public:
		Core();
		~Core();
        void    loop();
};

#endif /* !CORE_HPP_ */
