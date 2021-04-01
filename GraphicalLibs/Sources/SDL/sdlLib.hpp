/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** sdlib.hpp
*/

#include "IGfx.hpp"

#ifndef SDLLIB_HPP
#define SDLLIB_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#include <vector>

class sdlLib : public IGfx
{
    private:
        SDL_Window *window;
        SDL_Renderer *backGround;

        std::vector<SDL_Texture *> listText;
    public:
        sdlLib();

        bool init(const std::string &map);
        Key getKeyPressed();
        void clear();
        void drawRect(size_t x, size_t y, Rects fion);
        void drawText(size_t x, size_t y, std::string text);
        void refresh();
};

#endif