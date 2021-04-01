/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** game test hpp
*/

#include "IGame.hpp"



#include <iostream>
#include <vector>


class Game : public IGame
{
    private:
        std::vector<std::string> _map;
        IGfx* _gfx;

        void parser() const;
    public:
        Game();

        void init(IGfx *gfx, const std::string &map);
        void run();
        void display() const;
};