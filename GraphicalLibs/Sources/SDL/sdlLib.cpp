/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** sdl lib
*/

#include "sdlLib.hpp"

sdlLib::sdlLib()
{
}

bool sdlLib::init(const std::string &nth)
{
    (void)nth;

    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "error initializing SDL: " << SDL_GetError() << std::endl;
        return false;
    }
    window = SDL_CreateWindow("GAME",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    1920, 1080, SDL_RENDERER_ACCELERATED);

    backGround = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderClear(backGround);
    SDL_RenderPresent(backGround);

    return true;
}

Key sdlLib::getKeyPressed()
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
void sdlLib::clear()
{
    SDL_RenderClear(backGround);
    for (SDL_Texture *texture : listText) {
        SDL_DestroyTexture(texture);
    }
}

void sdlLib::drawRect(size_t x, size_t y, Rects entity)
{
    SDL_Texture *text = NULL;
    listText.push_back(text);
    if (entity == WALL) {
        text = IMG_LoadTexture(backGround, "GraphicalLibs/Sources/SDL/bin/wall.jpg");
    } else if (entity == BACKGROUND) {
        text = IMG_LoadTexture(backGround, "GraphicalLibs/Sources/SDL/bin/background.png");
    } else if (entity == PLAYER) {
        text = IMG_LoadTexture(backGround, "GraphicalLibs/Sources/SDL/bin/pacmanStrong.png");
    } else if (entity == ENEMY) {
        text = IMG_LoadTexture(backGround, "GraphicalLibs/Sources/SDL/bin/pacmanWeak.png");
    }

    SDL_Rect src;
    SDL_Rect dst;

    src.x = 0;
    src.y = 0;
    src.h = 50;
    src.w = 50;

    dst.x = x * 25;
    dst.y = y * 25;
    dst.h = 25;
    dst.w = 25;

    SDL_RenderCopy(backGround, text, &src, &dst);
}

void sdlLib::drawText(size_t x, size_t y, std::string text)
{
    (void)x;
    (void)y;
    (void)text;

}

void sdlLib::refresh()
{
    SDL_RenderPresent(backGround);
}

extern "C" IGfx *createGFX()
{
    return (new sdlLib);
}

extern "C" void destroyGFX(IGfx *lib)
{
    delete lib;
}