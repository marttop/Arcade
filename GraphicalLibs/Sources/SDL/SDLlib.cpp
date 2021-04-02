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
}

bool SDLlib::init(const std::string &map, std::map<char, std::string> tileMap)
{
    (void)map;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    _window = SDL_CreateWindow(
        "GAME",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1920,
        1080,
        SDL_RENDERER_ACCELERATED
    );

    for (auto itr : tileMap) {
        _listText.insert(std::make_pair(itr.first, IMG_LoadTexture(this->_background, itr.second.c_str())));
    }

    _background = SDL_CreateRenderer(_window, -1, 0);
    SDL_RenderClear(_background);
    SDL_RenderPresent(_background);

    return true;
}

void SDLlib::display(std::vector<std::string> map)
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

    SDL_RenderClear(this->_background);

    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            c = map[i][j];

            dst.x = j * 25;
            dst.y = i * 25;

            SDL_RenderCopy(_background, _listText[c], &src, &dst);
        }
    }
    SDL_RenderPresent(this->_background);
}

Key SDLlib::getKeyPressed()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return (K_EXIT);
        if (event.key.keysym.sym == SDLK_LEFT)
            return (K_LEFT);
        if (event.key.keysym.sym == SDLK_RIGHT)
            return (K_RIGHT);
        if (event.key.keysym.sym == SDLK_DOWN)
            return (K_DOWN);
        if (event.key.keysym.sym == SDLK_UP)
            return (K_UP);
    }

    return (NONE);
}

void SDLlib::drawText(size_t x, size_t y, std::string text)
{
    (void)x;
    (void)y;
    (void)text;
}

extern "C" IGfx *createGFX()
{
    return (new SDLlib);
}

extern "C" void destroyGFX(IGfx *lib)
{
    delete lib;
}