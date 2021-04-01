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
#include "Map.hpp"

#define LEFT_ARROW 68
#define RIGHT_ARROW 67
#define UP_ARROW 65
#define DOWN_ARROW 66

class Map;

class Player {
    public:
        Player(Map *map);
        ~Player();
        int drawSnake(void);
        int moveSnake(char c);
        int getScore(void);

    protected:
    private:
        void growSnake(void);

        int _x;
        int _y;
        int _score = 0;
        Map *_map;
        std::pair<int, std::pair<int, int>> _snakeEnd;
        std::vector<std::pair<int, std::pair<int, int>>> _snake;
};

#endif /* !PLAYER_HPP_ */