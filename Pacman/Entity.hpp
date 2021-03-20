/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "Map.hpp"

class Entity {
    public:

        enum EntityType {
            PLAYER,
            GHOST
        };

        enum Direction {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            NONE
        };

        Entity(EntityType type, Map *map);
        ~Entity();

        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
    protected:
    private:
        void _getPos();

        Map *_map;
        EntityType _type;
        char _carac;
        int _x;
        int _y;
        Direction _dir;
};

#endif /* !ENTITY_HPP_ */