/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** main
*/

#include "IGame.hpp"
#include "IGfx.hpp"
#include "DL.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Using: ./arcade lib" << std::endl;
        return (0);
    }
    typedef IGame *createGame();
    typedef void destroyGame(IGame *i);
    typedef IGfx *createGFX();
    typedef void destroyGFX(IGfx *i);
    // dl.error();
    // exit(0);


    DL dl2;
    dl2.open("lib/arcade_pacman.so", RTLD_LAZY | RTLD_GLOBAL);
    createGame *game = (createGame *)dl2.sym("createGame");
    IGame *_game = game();

    DL dl;
    dl.open(av[1], RTLD_LAZY | RTLD_GLOBAL);
    createGFX *lib = (createGFX *)dl.sym("createGFX");
    IGfx *_lib = lib();

    _lib->init("");
    _game->init(_lib, "nullptr");
    _game->run();
    return (0);
}