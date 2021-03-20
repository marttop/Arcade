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

class Map {
    public:
        Map();
        ~Map();
        void PrintMap(void);
        int GetRowCount(void);
        int GetColCount(void);
        int SetSnake(int x, int y);

    protected:
    private:
        void _CreateMap(void);
        void _ClearMap(void);
        void _SpawnFruit(void);

        char **_map;
        int _rowCount;
        int _colCount;
        int _isFruit;
};

#endif /* !MAP_HPP_ */