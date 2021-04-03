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

#include <ctime>
#include <vector>
#include <iostream>
#include <map>

class SDLlib : public IGfx
{
    public:
        SDLlib();
        ~SDLlib();

        bool init(const std::string &map, std::map<char, std::string>);
        Key getKeyPressed();
        void drawText(size_t x, size_t y, std::string text);
        void draw(std::vector<std::string>);
        void clear();
        void display();

    private:
        SDL_Window *_window;
        SDL_Renderer *_background;
        SDL_Texture *_texture;
        std::map<char, std::string> _listText;
};

#endif