##
## EPITECH PROJECT, 2021
## Mini-Pacman
## File description:
## Makefile
##

SRC			=	SFMLlib.cpp

CXXFLAGS 	+=	-Wall -Wextra -I../../Interface -I../../../Utils -fPIC -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -g3
NAME 		= 	../../../lib/arcade_sfml.so

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