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
}

Pacman::~Pacman()
{
}

void Pacman::init(const std::string &map)
{
    (void)map;
}

void Pacman::moveGhosts()
{
    for (size_t i = 0; i < this->g.size(); i++) {
        this->g[i]->moveGhost();
        this->g[i]->move();
    }
}

void Pacman::createGhosts()
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

void Pacman::update()
{
    static clock_t currTime = 0;
    static clock_t prevTime = 0;
    currTime = std::clock();

	if (this->_input != NONE)
		this->_p->setDir(this->_input);
	if (currTime - prevTime >= 100000) {
		this->_p->move();
        this->moveGhosts();
		prevTime = currTime;
	}
}

std::vector<std::string> Pacman::getMap() const
{
    return (m.map);
}

size_t Pacman::getScore() const
{
    return (m.getScore());
}

void Pacman::setKeyPressed(Key k)
{
    this->_input = k;
}

std::map<char, std::string> Pacman::getTiles() const
{
    std::map<char, std::string> tileMap;

    tileMap.insert(std::make_pair('#', "assets/wall.png"));
    tileMap.insert(std::make_pair('@', "assets/pacman.png"));
    tileMap.insert(std::make_pair('G', "assets/gum.png"));

    return (tileMap);
}

extern "C" IGame *createGame()
{
    return (new Pacman);
}

extern "C" void destroyGame(IGame *game)
{
    delete game;
}