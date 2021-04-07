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
        Map(std::string snakeParts);
        ~Map();
        int getRowCount(void);
        int getColCount(void);
        int setSnake(int x, int y, char part, std::string snakeParts);
        void clearMap(std::string snakeParts);
        std::vector<std::string> getMap() const;
        void setChar(int x, int y, char part);
        size_t getScore() const;

    protected:
    private:
        void spawnFruit(std::string snakeParts);
        void readMap();

        std::vector<std::string> _map;
        int _rowCount;
        int _colCount;
        int _isFruit;
        std::ifstream _file;
        std::string _wallParts;
        std::string _fruits;
        size_t _score;
        size_t _fruitValue;
};

#endif /* !MAP_HPP_ */