/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** lib graphique interface
*/

#include <string>
#include <iostream>

#ifndef IGFX_HPP
#define IGFX_HPP

typedef enum Key
{
    K_LEFT = 0,
    K_RIGHT,
    K_UP,
    K_DOWN,
    K_SPACE,
    K_ESC,
    K_EXIT,
    NONE,
} Key;

typedef enum Rects
{
    WALL,
    PLAYER,
    ENEMY,
    BACKGROUND,
} Rects;

class IGfx {
    public:
        virtual ~IGfx(){};
        virtual bool init(const std::string &map) = 0;
        virtual Key getKeyPressed() = 0;
        virtual void clear() = 0;
        virtual void drawRect(size_t x, size_t y, Rects fion) = 0;
        virtual void drawText(size_t x, size_t y, std::string text) = 0;
        virtual void refresh() = 0;
};

#endif