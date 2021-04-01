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

    // SDL_SetRenderDrawColor(backGround, 0, 0, 255, 255);
    SDL_RenderClear(backGround);
    SDL_RenderPresent(backGround);

    return true;
}

Key sdlLib::getKeyPressed()
{
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return K_EXIT;
    }

    return NONE;
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
        text = IMG_LoadTexture(backGround, "bin/wall.jpg");
    } else if (entity == BACKGROUND) {
        text = IMG_LoadTexture(backGround, "bin/background.png");
    } else if (entity == PLAYER) {
        text = IMG_LoadTexture(backGround, "bin/pacmanStrong.png");
    } else if (entity == ENEMY) {
        text = IMG_LoadTexture(backGround, "bin/pacmanWeak.png");
    }

    SDL_Rect src;
    SDL_Rect dst;

    src.x = 0;
    src.y = 0;
    src.h = 50;
    src.w = 50;

    dst.x = x;
    dst.y = y;
    dst.h = 50 / 2;
    dst.w = 50 / 2;

    SDL_RenderCopy(backGround, text, &src, &dst);
}

void sdlLib::drawText(size_t x, size_t y, std::string text)
{

}

void sdlLib::refresh()
{
    SDL_RenderPresent(backGround);
}