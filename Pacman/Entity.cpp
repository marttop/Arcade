/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(EntityType type, Map *map)
{
    this->_type = type;
    this->_map = map;
    if (this->_type == PLAYER) {
        this->_carac = '@';
    }
    else
        this->_carac = 'G';
    this->_getPos();
    std::cout << this->_map->map[this->_y][this->_x] << std::endl;
    this->_dir = NONE;
}

void Entity::Entity::_getPos()
{
    int i = 0;
    for (std::string s : this->_map->map) {
        if (s.find('@', 0) != std::string::npos)
            break;
        i++;
    }
    if (i != 0) {
        this->_y = i;
        this->_x = this->_map->map[i].find('@', 0);
    }
}

Entity::~Entity()
{
}

void Entity::Entity::moveUp()
{

}

void Entity::Entity::moveDown()
{

}

void Entity::Entity::moveLeft()
{

}

void Entity::Entity::moveRight()
{

}
