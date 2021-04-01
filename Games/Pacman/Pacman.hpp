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
#include "IGame.hpp"

class Pacman : public IGame {
    public:
        Pacman();
        ~Pacman();

        void init(IGfx *gfx, const std::string &map);
        void run();
        void display() const;
    protected:
    private:
        void createGhosts();
        void moveGhosts();
        void parser() const;
        Key _input;
        Player *_p;
        IGfx *_lib;
        std::vector<Ghost *> g;
        Map m;
};

#endif /* !PACMAN_HPP_ */
