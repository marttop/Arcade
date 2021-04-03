/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** sdl lib
*/

#include "SDLlib.hpp"

SDLlib::SDLlib()
{
}

SDLlib::~SDLlib()
{
    SDL_DestroyWindow(_window);
}

bool SDLlib::init(const std::string &map, std::map<char, std::string> tileMap)
{
    (void)map;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    _window = SDL_CreateWindow(
        "SDL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1920,
        1080,
        SDL_RENDERER_ACCELERATED
    );

    this->_texture = nullptr;
    _listText = tileMap;

    _background = SDL_CreateRenderer(_window, -1, 0);
    SDL_RenderClear(_background);
    SDL_RenderPresent(_background);

    return true;
}

void SDLlib::display()
{
    SDL_RenderPresent(this->_background);
}

void SDLlib::draw(std::vector<std::string> map)
{
    SDL_Rect dst;
    SDL_Rect src;
    char c;

    src.x = 0;
    src.y = 0;
    src.h = 50;
    src.w = 50;
    dst.h = 25;
    dst.w = 25;

    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            c = map[i][j];

            dst.x = j * 25;
            dst.y = i * 25;
            this->_texture = nullptr;
            this->_texture = IMG_LoadTexture(this->_background, _listText[c].c_str());
            SDL_QueryTexture(this->_texture, NULL, NULL, &dst.w, &dst.h);
            SDL_QueryTexture(this->_texture, NULL, NULL, &src.w, &src.h);

            if (dst.w == 32 && dst.h == 32) {
                dst.w = 25;
                dst.h = 25;
            }

            SDL_RenderCopy(_background, this->_texture, &src, &dst);
            SDL_DestroyTexture(this->_texture);
        }
    }
}

Key SDLlib::getKeyPressed()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return (K_EXIT);
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_LEFT)
                return (K_LEFT);
            if (event.key.keysym.sym == SDLK_RIGHT)
                return (K_RIGHT);
            if (event.key.keysym.sym == SDLK_DOWN)
                return (K_DOWN);
            if (event.key.keysym.sym == SDLK_UP)
                return (K_UP);
            if (event.key.keysym.sym == SDLK_1)
                return (K_PREV_LIB);
            if (event.key.keysym.sym == SDLK_2)
                return (K_NEXT_LIB);
            if (event.key.keysym.sym == SDLK_3)
                return (K_PREV_GAME);
            if (event.key.keysym.sym == SDLK_4)
                return (K_NEXT_GAME);
            if (event.key.keysym.sym == SDLK_SPACE)
                return (K_SPACE);
        }
    }

    return (NONE);
}

void SDLlib::drawText(size_t x, size_t y, std::string text)
{
    (void)x;
    (void)y;
    (void)text;
}

void SDLlib::clear()
{
    SDL_RenderClear(this->_background);
}

extern "C" IGfx *createGFX()
{
    return (new SDLlib);
}

extern "C" void destroyGFX(IGfx *lib)
{
    delete lib;
}