/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** main
*/
#include "Pacman.hpp"

int main(void)
{
	try {
        Pacman game;
		game.launch();
	}
	catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
		return (84);
	}
}