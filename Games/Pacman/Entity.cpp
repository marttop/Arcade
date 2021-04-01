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
        this->_getPos();
    }
    else
        this->_carac = 'G';
    this->_dir = NONE;
    this->_on = ' ';
}

void Entity::Entity::_getPos()
{
    int i = 0;
    for (std::string s : this->_map->map) {
        if (s.find(this->_carac, 0) != std::string::npos)
            break;
        i++;
    }
    if (i != 0) {
        this->_y = i;
        this->_x = this->_map->map[i].find(this->_carac, 0);
    }
}

Entity::~Entity()
{
}

void Entity::Entity::setDir(Key dir)
{
    switch (dir) {
        case K_UP:
            _dir = UP;
            break;
        case K_DOWN:
            _dir = DOWN;
            break;
        case K_LEFT:
            _dir = LEFT;
            break;
        case K_RIGHT:
            _dir = RIGHT;
            break;
        default:
            break;
    }
}

void Entity::Entity::move()
{
    switch (this->_dir) {
        case UP:
            this->moveUp();
            break;
        case DOWN:
            this->moveDown();
            break;
        case LEFT:
            this->moveLeft();
            break;
        case RIGHT:
            this->moveRight();
            break;
        default:
            break;
    }
}

void Entity::Entity::moveUp()
{
    if (this->_y > 0) {
        if ((this->_map->map[_y - 1][_x] == '.' || this->_map->map[_y - 1][_x] == ' ') && this->_type == PLAYER) {
            if (this->_map->map[_y - 1][_x] == '.')
                this->_map->setScore(this->_map->getScore() + 1);
            this->_map->map[_y - 1][_x] = this->_carac;
            this->_map->map[_y][_x] = ' ';
            this->_on = ' ';
            this->_y -= 1;
        }
        else if ((this->_map->map[_y - 1][_x] == '.' || this->_map->map[_y - 1][_x] == ' ') && this->_type == GHOST) {
            this->_map->map[_y][_x] = this->_on;
            this->_on = this->_map->map[_y - 1][_x];
            this->_map->map[_y - 1][_x] = this->_carac;
            this->_y -= 1;
        }
        else
            this->_dir = NONE;
    }
}

void Entity::Entity::moveDown()
{
    if (this->_y < this->_map->map.size() - 1) {
        if ((this->_map->map[_y + 1][_x] == '.' || this->_map->map[_y + 1][_x] == ' ') && this->_type == PLAYER) {
            if (this->_map->map[_y + 1][_x] == '.')
                this->_map->setScore(this->_map->getScore() + 1);
            this->_map->map[_y + 1][_x] = this->_carac;
            this->_map->map[_y][_x] = ' ';
            this->_on = ' ';
            this->_y += 1;
        }
        else if ((this->_map->map[_y + 1][_x] == '.' || this->_map->map[_y + 1][_x] == ' ') && this->_type == GHOST) {
            this->_map->map[_y][_x] = this->_on;
            this->_on = this->_map->map[_y + 1][_x];
            this->_map->map[_y + 1][_x] = this->_carac;
            this->_y += 1;
        }
        else
            this->_dir = NONE;
    }
}

void Entity::Entity::moveLeft()
{
    if (this->_x > 0) {
        if ((this->_map->map[_y][_x - 1] == '.' || this->_map->map[_y][_x - 1] == ' ') && this->_type == PLAYER) {
            if (this->_map->map[_y][_x - 1] == '.')
                this->_map->setScore(this->_map->getScore() + 1);
            this->_map->map[_y][_x - 1] = this->_carac;
            this->_map->map[_y][_x] = ' ';
            this->_on = ' ';
            this->_x -= 1;
        }
        else if ((this->_map->map[_y][_x - 1] == '.' || this->_map->map[_y][_x - 1] == ' ') && this->_type == GHOST) {
            this->_map->map[_y][_x] = this->_on;
            this->_on = this->_map->map[_y][_x - 1];
            this->_map->map[_y][_x - 1] = this->_carac;
            this->_x -= 1;
        }
        else
            this->_dir = NONE;
    }
    else if (this->_x == 0 && this->_y == 11) {
        this->_map->map[_y][this->_map->map[_y].size() - 1] = this->_carac;
        this->_map->map[_y][_x] = ' ';
        this->_on = ' ';
        this->_x = this->_map->map[_y].size() - 1;
    }
}

void Entity::Entity::moveRight()
{
    if (this->_x < this->_map->map[_y].size() - 1) {
        if ((this->_map->map[_y][_x + 1] == '.' || this->_map->map[_y][_x + 1] == ' ') && this->_type == PLAYER) {
            if (this->_map->map[_y][_x + 1] == '.')
                this->_map->setScore(this->_map->getScore() + 1);
            this->_map->map[_y][_x + 1] = this->_carac;
            this->_map->map[_y][_x] = ' ';
            this->_on = ' ';
            this->_x += 1;
        }
        else if ((this->_map->map[_y][_x + 1] == '.' || this->_map->map[_y][_x + 1] == ' ') && this->_type == GHOST) {
            this->_map->map[_y][_x] = this->_on;
            this->_on = this->_map->map[_y][_x + 1];
            this->_map->map[_y][_x + 1] = this->_carac;
            this->_x += 1;
        }
        else
            this->_dir = NONE;
    }
    else if (this->_x == this->_map->map[_y].size() - 1 && this->_y == 11) {
        this->_map->map[_y][0] = this->_carac;
        this->_map->map[_y][_x] = ' ';
        this->_on = ' ';
        this->_x = 0;
    }
}