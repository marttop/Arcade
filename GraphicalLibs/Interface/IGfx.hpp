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
#include <map>
#include <vector>

class IGfx {
    public:
        virtual ~IGfx(){};
        virtual bool init(const std::string &map, std::map<char, std::string>) = 0;
        virtual Key getKeyPressed() = 0;
        virtual void drawText(size_t x, size_t y, std::string text) = 0;

        virtual void draw(std::vector<std::string>) = 0;
        virtual void display() = 0;
        virtual void clear() = 0;
};

#endif