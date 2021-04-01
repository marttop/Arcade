/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "Utils.hpp"
#include "Player.hpp"
#include "Ghost.hpp"

class Pacman {
    public:
        Pacman();
        ~Pacman();

        void launch();
        void gameInterface();
    protected:
    private:
        void _createGhosts();
        void _moveGhosts();
        char _input;
        Player *p;
        std::vector<Ghost *> g;
        Map m;
};

#endif /* !PACMAN_HPP_ */
