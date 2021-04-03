##
## EPITECH PROJECT, 2021
## Mini-Snake
## File description:
## Makefile
##

SRC			=	Map.cpp \
				Player.cpp \

CXXFLAGS 	+=	-Wall -Wextra -I../../Utils -I../Interface -fPIC -g3
NAME 		= 	../../lib/arcade_nibbler.so

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -shared -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re