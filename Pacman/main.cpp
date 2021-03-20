/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** main
*/

#include "Entity.hpp"
#include "Utils.hpp"



int main(void)
{
	try {
        Map m;
		Entity *player = new Entity(Entity::PLAYER, &m);
    	for (char c = 0; (c = getch()) != 'x';) {
			if (c != 0)
				player->setDir((Entity::Direction)c);
			player->move();
    	}
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
}