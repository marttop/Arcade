##
## EPITECH PROJECT, 2021
## Mini-Pacman
## File description:
## Makefile
##

SRC			=	sdlLib.cpp

CXXFLAGS 	+=	-Wall -Wextra -I../../Interface -I./Utils -fPIC -lSDL2main -lSDL2 -lSDL2_image -g3
NAME 		= 	../../../lib/arcade_sdl2.so

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	g++ $(OBJ) -shared -o $(NAME) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re