/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(char *lib)
{
    this->_dlGfx.open(lib, RTLD_LAZY | RTLD_GLOBAL);
    createGFX *gfx = (createGFX *)this->_dlGfx.sym("createGFX");
    this->_lib = gfx();

    this->_dlGame.open((char *)"lib/arcade_pacman.so", RTLD_LAZY | RTLD_GLOBAL);
    createGame *game = (createGame *)this->_dlGame.sym("createGame");
    this->_game = game();


    this->_game->init("");
    std::map<char, std::string> tileMap = this->_game->getTiles();
    this->_lib->init("", tileMap);
}

void Core::run()
{
    Key k;
    while ((k = this->_lib->getKeyPressed()) != K_EXIT) {
        this->_game->setKeyPressed(k);
        this->_game->update();
        this->_lib->display(this->_game->getMap());
    }
}

Core::~Core()
{
}
