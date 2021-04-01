##
## EPITECH PROJECT, 2021
## Mini-Pacman
## File description:
## Makefile
##

SRC			=	Map.cpp \
				Entity.cpp \
				Utils.cpp \
				Player.cpp \
				Pacman.cpp \
				Ghost.cpp

CXXFLAGS 	=	-Wall -Wextra -I./Utils -I../Interface -fPIC
NAME 		= 	../../lib/arcade_pacman.so

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