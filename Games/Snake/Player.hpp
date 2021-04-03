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

class Map;

class Player : public IGame {
    public:
        Player();
        ~Player();

        void init(const std::string &map);
        bool update();
        std::vector<std::string> getMap() const;
        size_t getScore() const;
        void setKeyPressed(Key k);
        std::map<char, std::string> getTiles() const;

    protected:
    private:
        void growSnake(void);
        int moveSnake(char c);
        int drawSnake(void);

        int _x;
        int _y;
        size_t _score;
        Map *_map;
        Key _input;
        std::pair<int, std::pair<int, int>> _snakeEnd;
        std::vector<std::pair<int, std::pair<int, int>>> _snake;
};

#endif /* !PLAYER_HPP_ */