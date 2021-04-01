/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Ghost
*/

#include "Ghost.hpp"

Ghost::Ghost(Map *map, int x, int y) : Entity(GHOST, map)
{
    this->_x = x;
    this->_y = y;
    this->_dir = UP;
    this->start = 0;
}

void Ghost::Ghost::moveGhost()
{
    if (this->_dir == NONE) {
        int i = 0;
        i = std::rand() % 4;
        if (this->start == 0) {
            if (this->_x % 2 == 0) this->_dir = RIGHT;
            else this->_dir = LEFT;
            this->start++;
            return;
        }
        if (i == 0) this->_dir = DOWN;
        if (i == 1) this->_dir = UP;
        if (i == 2) this->_dir = LEFT;
        if (i == 3) this->_dir = RIGHT;
    }
}

Ghost::~Ghost()
{
}
