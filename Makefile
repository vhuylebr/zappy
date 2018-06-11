##
## EPITECH PROJECT, 2018
## zappy
## File description:
## makefile
##

all:	zappy_server zappy_ai

zappy_server:
		make -C server/

zappy_ai:
		make -C client/

clean:
		make clean -C server/
		make clean -C client/

fclean: clean
	make fclean -C server/
	make fclean -C client/

re: fclean all

.PHONY: all clean fclean re
