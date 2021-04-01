/*
** EPITECH PROJECT, 2021
** Mini-Snake
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Score.hpp"

class Player;

class Map {
    public:
        Map();
        ~Map();
        void printMap(void);
        int getRowCount(void);
        int getColCount(void);
        int setSnake(int x, int y);
        int drawAsciiGame(Player &player, int topScore);

    protected:
    private:
        void createMap(void);
        void clearMap(void);
        void spawnFruit(void);

        char **_map;
        int _rowCount;
        int _colCount;
        int _isFruit;
};

#endif /* !MAP_HPP_ */