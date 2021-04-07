/*
** EPITECH PROJECT, 2021
** MiniSnake
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>
#include <utility>
#include <ctime>
#include <map>
#include "Map.hpp"
#include "Key.hpp"
#include "IGame.hpp"
#include <chrono>

using my_clock = std::chrono::high_resolution_clock;

class Map;

class Player : public IGame {
    public:
        Player();
        ~Player();

        enum Snake {
            HEAD_UP,
            HEAD_DOWN,
            HEAD_LEFT,
            HEAD_RIGHT,
            STRAIGHT_UPDOWN,
            STRAIGHT_LEFTRIGHT,
            TAIL_UP,
            TAIL_DOWN,
            TAIL_LEFT,
            TAIL_RIGHT,
            TURN1,
            TURN2,
            TURN3,
            TURN4
        };

        void init();
        bool update();
        std::vector<std::string> getMap() const;
        size_t getScore() const;
        void setKeyPressed(Key k);
        std::string getName() const;
        std::map<char, std::string> getTiles() const;
        size_t getBestScore() const;
        void endGame();

    protected:
    private:
        void growSnake(void);
        int moveSnake(char c);
        int drawSnake(void);
        void getScoreFromFile();
        void setScoreToFile();

        size_t _bestScore;
        int _x;
        int _y;
        Map *_map;
        Key _input;
        std::string _name;
        std::pair<int, std::pair<int, int>> _snakeEnd;
        std::vector<std::pair<int, std::pair<int, int>>> _snake;
        std::string _snakeParts;
        int _lost;
        std::chrono::_V2::system_clock::time_point _currLostClock;
        std::chrono::_V2::system_clock::time_point _prevLostClock;
};

#endif /* !PLAYER_HPP_ */