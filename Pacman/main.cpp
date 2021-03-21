/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** main
*/

#include "Entity.hpp"
#include "Utils.hpp"
#include "Player.hpp"

void gameInterface(Map *m, Player *player, char c)
{
    static clock_t currTime = 0;
    static clock_t prevTime = 0;

    currTime = std::clock();
	if (c != 0)
		player->setDir((Entity::Direction)c);
	if (currTime - prevTime >= 100000) {
		std::cout << "\e[1;1H\e[2J";
		player->move();
		std::cout << "Score: " << m->getScore() << std::endl << std::endl;
		m->printMap();
		prevTime = currTime;
	}
}

int main(void)
{
	try {
        Map m;
		Player *player = new Player(&m);
    	for (char c = 0; (c = getch()) != 'x';) {
			gameInterface(&m, player, c);
    	}
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
}