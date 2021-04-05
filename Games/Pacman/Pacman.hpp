/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "Player.hpp"
#include "Ghost.hpp"
#include "IGame.hpp"
#include <chrono>
#include <math.h>


using my_clock = std::chrono::high_resolution_clock;

class Pacman : public IGame {
    public:
        Pacman();
        ~Pacman();

        void init();
        std::vector<std::string> getMap() const;
        size_t getScore() const;
        void setKeyPressed(Key k);
        std::map<char, std::string> getTiles() const;
        size_t getBestScore() const;
        std::string getName() const;

    protected:
    private:
        void createGhosts();
        void moveGhosts();
        bool update();
        void getScoreFromFile();
        void setScoreToFile();

        void setWeakGhost();
        void setStrongGhost();
        Ghost *findGhost(size_t x, size_t y) const;
        void overGhost();
        bool underGhost();
        bool noMorePoint();

        void endGame();

        bool _timer;

        bool _end;
        bool _win;

        int _combo;

        size_t _bestScore;
        std::string _name;
        Key _input;
        Player *_p;
        std::vector<Ghost *> g;
        Map m;
};

#endif /* !PACMAN_HPP_ */
