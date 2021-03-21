/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Ghost
*/

#ifndef GHOST_HPP_
#define GHOST_HPP_

#include "Entity.hpp"

class Ghost : public Entity {
    public:
        Ghost(Map *map, int x, int y);
        ~Ghost();
        void moveGhost();
    protected:
    private:
        int start;
};

#endif /* !GHOST_HPP_ */
