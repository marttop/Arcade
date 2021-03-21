##
## EPITECH PROJECT, 2021
## Mini-Pacman
## File description:
## Makefile
##

SRC			= 	main.cpp \
				Map.cpp \
				Entity.cpp \
				Utils.cpp \
				Player.cpp

CXXFLAGS 	=	-Wall -Wextra -g3 -O0
NAME 		= 	Pacman

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re