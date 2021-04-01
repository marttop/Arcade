/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "IGfx.hpp"

class IGame {
    public:
        virtual ~IGame(){};
        virtual void init(IGfx *gfx, const std::string &map) = 0;
        virtual void run() = 0;
        virtual void display() const = 0;
};

#endif /* !IGAME_HPP_ */
