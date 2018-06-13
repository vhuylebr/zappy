##
## EPITECH PROJECT, 2018
## zappy
## File description:
## server's makefile
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror -I./include/

NAME	=	zappy_server

SRCS	=	src/main.c		\
		src/fill_info.c		\
		src/flag.c		\
		src/tools.c		\
		src/tools2.c		\
		src/handle_clients.c	\
		src/server_init.c	\
		src/get_next_line.c	\
		src/get_next_line2.c	\
		src/wordtab.c	\
		src/handle_commands.c	\
		src/handle_client_list.c	\
		src/init_map.c			\
		src/handle_team.c	\
		cmd/broadcast.c			\
		cmd/eject.c				\
		cmd/fork.c 				\
		cmd/gui_cmd.c 			\
		cmd/gui_cmd2.c 			\
		cmd/incantation.c		\
		cmd/look.c 				\
		cmd/movement.c 			\
		cmd/object.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
