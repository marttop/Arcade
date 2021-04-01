/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** main
*/
#include "Pacman.hpp"
#include "sdlLib.hpp"

int main(void)
{
    Pacman jeux;
    sdlLib fuck;

    fuck.init("yesy");

    jeux.init(&fuck, "cool");
    jeux.run();
}