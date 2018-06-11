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
		src/handle_clients.c	\
		src/server_init.c

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
