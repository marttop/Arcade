/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** game interface
*/

#include "IGfx.hpp"

#ifndef IGAME_HPP
#define IGAME_HPP

class IGame {
    public:
        virtual ~IGame(){};
        virtual void init(IGfx *gfx, const std::string &map) = 0;
        virtual void run() = 0;
        virtual void display() const = 0;
};

#endif