/*
** EPITECH PROJECT, 2021
** main
** File description:
** a
*/

#include "game.hpp"
#include "sdlLib.hpp"

int main(void)
{
    Game jeux;
    sdlLib gfx;

    gfx.init("yesy");

    jeux.init(&gfx, "cool");
    jeux.run();
}
