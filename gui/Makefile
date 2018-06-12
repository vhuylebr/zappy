##
## EPITECH PROJECT, 2018
## zappy
## File description:
## gui's makefile
##

CXX	=	g++

RM	=	rm -rf

CPPFLAGS	= -I./headers/

NAME	=	zappy_gui

SRCS	=	src/main.cpp		\
			src/Core.cpp	\
			src/Socket.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
