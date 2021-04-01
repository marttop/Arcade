/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman()
{
    std::srand(std::time(0));
    this->p = new Player(&this->m);
    this->_createGhosts();
}

Pacman::~Pacman()
{
}

void Pacman::Pacman::_createGhosts()
{
    int nb = 0;
    for (size_t i = 0; i < this->m.map.size(); i++) {
        for (size_t j = 0; j < this->m.map[i].size(); j++) {
            if (this->m.map[i][j] == 'G') {
                this->g.push_back(new Ghost(&this->m, j, i));
                nb++;
            }
        }
    }
}

void Pacman::Pacman::_moveGhosts()
{
    for (size_t i = 0; i < this->g.size(); i++) {
        this->g[i]->moveGhost();
        this->g[i]->move();
    }
}

void Pacman::Pacman::gameInterface()
{
    static clock_t currTime = 0;
    static clock_t prevTime = 0;

    currTime = std::clock();
	if (this->_input != 0)
		this->p->setDir((Entity::Direction)this->_input);
	if (currTime - prevTime >= 100000) {
		std::cout << "\e[1;1H\e[2J";
		this->p->move();
        this->_moveGhosts();
		std::cout << "Score: " << this->m.getScore() << std::endl << std::endl;
		this->m.printMap();
		prevTime = currTime;
	}
}

void Pacman::Pacman::launch()
{
    for (; (this->_input = getch()) != 'x';) {
		this->gameInterface();
    }
}