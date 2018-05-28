##
## EPITECH PROJECT, 2018
## nm_objdump
## File description:
## makefile
##

CC	= gcc

RM	= rm -f

SRC1	= 	server/main.c 		\
		server/fill_info.c	\
		server/tools.c		\
		server/flag.c

SRC2	=	ai/main.c

NAME1	= zappy_server

NAME2	= zappy_ai

CFLAGS	+= -I./include
CFLAGS	+= -Wall -Wextra -Werror

OBJS1	= $(SRC1:.c=.o)

OBJS2	= $(SRC2:.c=.o)

all:	zappy_server zappy_ai

zappy_server:	 $(OBJS1)
	 	$(CC) $(OBJS1) -o $(NAME1) $(CFLAGS)

zappy_ai: $(OBJS2)
	 $(CC) $(OBJS2) -o $(NAME2) $(CFLAGS)

clean:
	$(RM) $(OBJS1)
	$(RM) $(OBJS2)

fclean: clean
	$(RM) $(NAME1)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
