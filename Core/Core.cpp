/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(char *lib)
{
    this->_lib = nullptr;
    this->_game = nullptr;
    this->openGfx(lib);
    this->openGame((char *)"lib/arcade_pacman.so");
    this->_game->init("");
    this->_lib->init("", this->_game->getTiles());
    this->parseLibs();
    _libIdx = 0;
    for (size_t i = 0; i != _libNames.size(); i++) {
        if (strcmp(_libNames[i].c_str(), lib) == 0)
            break;
        _libIdx++;
    }
    _gameIdx = 0;
}

Core::~Core()
{
}

void Core::parseLibs()
{
    std::ifstream file;
    std::string line;
    file.open("db/libs/config.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.substr(line.find('=') + 1) == "game")
                _gameNames.push_back(line.substr(0, line.find('=')));
            if (line.substr(line.find('=') + 1) == "gfx")
                _libNames.push_back(line.substr(0, line.find('=')));
        }
        file.close();
    }
}

void Core::openGfx(const char *path)
{
    this->_dlGfx.open((char *)path, RTLD_LAZY | RTLD_GLOBAL);
    createGFX *gfx = (createGFX *)this->_dlGfx.sym("createGFX");
    this->_lib = gfx();
}

void Core::openGame(const char *path)
{
    this->_dlGame.open((char *)path, RTLD_LAZY | RTLD_GLOBAL);
    createGame *game = (createGame *)this->_dlGame.sym("createGame");
    this->_game = game();
}

void Core::changeGfxLib(const char *path)
{
    destroyGFX *dGfx = (destroyGFX *)this->_dlGfx.sym("destroyGFX");
    if (_lib != nullptr) dGfx(_lib);
    this->_dlGfx.close();
    this->openGfx(path);
    this->_lib->init("", this->_game->getTiles());
}

void Core::changeGameLib(const char *path)
{
    destroyGame *dGame = (destroyGame *)this->_dlGame.sym("destroyGame");
    if (_game != nullptr) dGame(_game);
    this->_dlGame.close();
    this->openGame(path);
    this->_game->init("");
}

void Core::handleKeyPressed()
{
    if (this->_k == K_PREV_LIB) {
        _libIdx--;
        if (_libIdx < 0) _libIdx = _libNames.size() - 1;
        this->changeGfxLib(_libNames[_libIdx].c_str());
        this->_k = NONE;
    }
    else if (this->_k == K_NEXT_LIB) {
        _libIdx++;
        if (_libIdx > (int)_libNames.size() - 1) _libIdx = 0;
        this->changeGfxLib(_libNames[_libIdx].c_str());
        this->_k = NONE;
    }
    else if (this->_k == K_PREV_GAME) {
        _gameIdx--;
        if (_gameIdx < 0) _gameIdx = _gameNames.size() - 1;
        this->changeGameLib(_gameNames[_gameIdx].c_str());
        this->_game->init("");
        this->_lib->init("", this->_game->getTiles());
        this->_k = NONE;
    }
    else if (this->_k == K_NEXT_GAME) {
        _gameIdx++;
        if (_gameIdx > (int)_gameNames.size() - 1) _gameIdx = 0;
        this->changeGameLib(_gameNames[_gameIdx].c_str());
        this->_game->init("");
        this->_lib->init("", this->_game->getTiles());
        this->_k = NONE;
    }
}

void Core::run()
{
    while ((this->_k = this->_lib->getKeyPressed()) != K_EXIT) {
        this->handleKeyPressed();
        this->_game->setKeyPressed(this->_k);
        this->_game->update();
        this->_lib->display(this->_game->getMap());
    }
}