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
#include <iostream>
#include <map>

class SDLlib : public IGfx
{
    private:
        SDL_Window *_window;
        SDL_Renderer *_background;

        std::map<char, std::string> _listText;
    public:
        SDLlib();
        ~SDLlib();


        bool init(const std::string &map, std::map<char, std::string>);
        void display(std::vector<std::string>);
        Key getKeyPressed();
        void drawText(size_t x, size_t y, std::string text);
};

#endif