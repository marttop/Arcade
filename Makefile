##
## EPITECH PROJECT, 2021
## G-JAM-001-NCE-0-2-jam-marton.szuts
## File description:
## Makefile
##

NAME			=	test

CXX				=	g++

DIR1			=	./GraphicalLibs/Interface/
DIR2			=	./Games/Pacman/
DIR3			=	./Games/Interface/
DIR4			=	./GraphicalLibs/Sources/SDL/

INC				=	$(DIR1) $(DIR2) $(DIR3) $(DIR4)
INC_PARAMS		=	$(foreach d, $(INC), -I$d)

CXXFLAGS		=	-Wall -Wextra $(INC_PARAMS)

LDFLAGS			=	-lSDL2main -lSDL2 -lSDL2_image -g3

SRC				=	./Games/Pacman/main.cpp \
					./Games/Pacman/Ghost.cpp \
					./Games/Pacman/Entity.cpp \
					./Games/Pacman/Map.cpp \
					./Games/Pacman/Player.cpp \
					./Games/Pacman/Pacman.cpp \
					./Games/Pacman/Utils.cpp \
					./GraphicalLibs/Sources/SDL/sdlLib.cpp \

OBJ				=	$(SRC:.cpp=.o)

RM				=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re