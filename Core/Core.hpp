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
};


#endif /* !CORE_HPP_ */
