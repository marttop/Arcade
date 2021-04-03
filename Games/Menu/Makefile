##
## EPITECH PROJECT, 2021
## Mini-Ass
## File description:
## Makefile
##

SRC			=	Menu.cpp

CXXFLAGS 	+=	-Wall -Wextra -I../../Utils -I../Interface -fPIC
NAME 		= 	../../lib/arcade_menu.so

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