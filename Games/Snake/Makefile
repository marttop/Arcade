##
## EPITECH PROJECT, 2021
## Mini-Snake
## File description:
## Makefile
##

SRC			= 	main.cpp \
				Map.cpp \
				Player.cpp \
				Utils.cpp \
				Score.cpp \

CXXFLAGS 	=	-I./Utils -Wall -Wextra -g3 -O0
NAME 		= 	Snake

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