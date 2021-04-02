##
## EPITECH PROJECT, 2021
## G-JAM-001-NCE-0-2-jam-marton.szuts
## File description:
## Makefile
##

NAME			=	arcade

CXX				=	g++

DIR1			=	./GraphicalLibs/Interface/
DIR2			=	./Core/
DIR3			=	./Games/Interface/
DIR4			=	./Utils/

CALL_MAKE_PACMAN	=	cd Games/Pacman && make
CALL_MAKE_SNAKE		=	cd Games/Snake && make
CALL_MAKE_SDL		=	cd GraphicalLibs/Sources/SDL && make
CALL_MAKE_SFML		=	cd GraphicalLibs/Sources/SFML && make

INC				=	$(DIR1) $(DIR2) $(DIR3) $(DIR4)
INC_PARAMS		=	$(foreach d, $(INC), -I$d)

CXXFLAGS		=	-Wall -Wextra $(INC_PARAMS) -ldl

SRC				=	./Core/main.cpp \
					./Core/DL.cpp \
					./Core/Core.cpp \

OBJ				=	$(SRC:.cpp=.o)

RM				=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CALL_MAKE_PACMAN)
	$(CALL_MAKE_SNAKE)
	$(CALL_MAKE_SDL)
	$(CALL_MAKE_SFML)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	$(RM) $(OBJ)
	cd Games/Pacman && make clean
	cd Games/Snake && make clean
	cd GraphicalLibs/Sources/SDL && make clean
	cd GraphicalLibs/Sources/SFML && make clean

fclean: clean
	$(RM) $(NAME)
	cd Games/Pacman && make fclean
	cd Games/Snake && make fclean
	cd GraphicalLibs/Sources/SDL && make fclean
	cd GraphicalLibs/Sources/SFML && make fclean

re: fclean all

.PHONY: all clean fclean re