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
#include <unistd.h>
#include <fstream>
#include "Player.hpp"

class Player;

class Map {
    public:
        Map();
        ~Map();
        int getRowCount(void);
        int getColCount(void);
        int setSnake(int x, int y);
        void clearMap(void);
        std::vector<std::string> getMap() const;

    protected:
    private:
        void spawnFruit(void);
        void readMap();

        std::vector<std::string> _map;
        int _rowCount;
        int _colCount;
        int _isFruit;
        std::ifstream _file;
};

#endif /* !MAP_HPP_ */