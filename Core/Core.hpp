/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include "DL.hpp"
#include "IGame.hpp"
#include "IGfx.hpp"
#include <ctime>
#include <cstring>
#include <fstream>

class Core {
    public:
        Core(char *lib);
        ~Core();
        void run();

    protected:
    private:
        typedef IGame *createGame();
        typedef void destroyGame(IGame *i);
        typedef IGfx *createGFX();
        typedef void destroyGFX(IGfx *i);

        IGame *_game;
        IGfx *_lib;
        DL _dlGame;
        DL _dlGfx;
        std::vector<std::string> _libNames;
        std::vector<std::string> _gameNames;
        int _libIdx;
        int _gameIdx;
        Key _k;

        void openGfx(const char *path);
        void openGame(const char *path);
        void changeGfxLib(const char *path);
        void changeGameLib(const char *path);
        void parseLibs();
        void handleKeyPressed();
};


#endif /* !CORE_HPP_ */
