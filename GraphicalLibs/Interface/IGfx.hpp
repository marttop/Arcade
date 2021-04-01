/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** lib graphique interface
*/

#ifndef IGFX_HPP
#define IGFX_HPP

#include <string>
#include "Key.hpp"

typedef enum Rects
{
    WALL,
    PACMAN,
    SNAKE_HEAD,
    SNAKE,
    GHOST,
    FRUIT,
    GUM,
    BUTTON,
    BACKGROUND,
} Rects;

class IGfx {
    public:
        virtual ~IGfx(){};
        virtual bool init(const std::string &map, std::vector<std::pair<Rects, std::string>>) = 0;
        virtual Key getKeyPressed() = 0;
        virtual void drawText(size_t x, size_t y, std::string text) = 0;
        virtual void display(std::vector<std::string>) = 0;
};

#endif