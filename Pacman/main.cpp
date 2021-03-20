/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** main
*/

#include "Entity.hpp"

int main(void)
{
	try {
        Map m;
        m.printMap();
		std::cout << std::endl;
		Entity *player = new Entity(Entity::PLAYER, &m);
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
}