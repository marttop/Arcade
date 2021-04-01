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
    this->_p = new Player(&this->m);
    this->createGhosts();
    this->_lib = nullptr;
}

Pacman::~Pacman()
{
}

void Pacman::init(IGfx *gfx, const std::string &map)
{
    (void)map;
    this->_lib = gfx;
}

void Pacman::run()
{
    for (; (this->_input = _lib->getKeyPressed()) != K_EXIT;) {
        static clock_t currTime = 0;
        static clock_t prevTime = 0;

        currTime = std::clock();
	    if (this->_input != 0)
	    	this->_p->setDir(this->_input);
	    if (currTime - prevTime >= 100000) {
	    	this->_p->move();
            this->moveGhosts();
	    	prevTime = currTime;
	    }
		this->display();
    }
}

void Pacman::display() const
{
    if (this->_lib) {
        this->_lib->clear();
        parser();
        _lib->refresh();
    }
}

void Pacman::parser() const
{
    for (size_t i = 0; i < this->m.map.size(); i++) {
        for (size_t j = 0; j < this->m.map[i].size(); j++) {
            char c = this->m.map[i][j];
            if (c == 'G') {
                this->_lib->drawRect(j, i, ENEMY);
            } else if (c == '#') {
                this->_lib->drawRect(j, i, WALL);
            } else if (c == '@') {
                this->_lib->drawRect(j, i, PLAYER);
            } else {
                this->_lib->drawRect(j, i, BACKGROUND);
            }
        }
    }
}


void Pacman::Pacman::createGhosts()
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

void Pacman::moveGhosts()
{
    for (size_t i = 0; i < this->g.size(); i++) {
        this->g[i]->moveGhost();
        this->g[i]->move();
    }
}