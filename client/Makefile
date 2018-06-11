##
## EPITECH PROJECT, 2018
## zappy
## File description:
## makefile client
##

CXX	=	g++

RM	=	rm -f

SRC	=	src/main.cpp		\
		src/fill_info.cpp	\
		src/flag.cpp		\
		src/tools.cpp

NAME	= ../zappy_ai

CXXFLAGS	= -I./include -Wall -Wextra -Werror

OBJS	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
