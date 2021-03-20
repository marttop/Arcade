/*
** EPITECH PROJECT, 2021
** Mini-Snake
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
    std::srand(std::time(0));
    _rowCount = 15;
    _colCount = 15;
    _isFruit = 0;
    _CreateMap();
}

Map::~Map()
{
    for (int i = 0; i < _rowCount; i++)
        delete []_map[i];
    delete []_map;
}

void Map::_CreateMap(void)
{
    _map = new char*[_rowCount + 1];
    for (int i = 0; i < _rowCount; i++) {
        _map[i] = new char[_colCount + 1];
        std::memset(_map[i], ' ', _colCount);
        _map[i][0] = '#';
        _map[i][_colCount - 1] = '#';
        _map[i][_colCount] = '\0';
    }
    _map[_rowCount] = NULL;
    std::memset(_map[0], '#',  _colCount);
    std::memset(_map[_rowCount - 1], '#',  _colCount);
    _SpawnFruit();
}

void Map::PrintMap(void)
{
    for (int i = 0; i < _rowCount; i++)
        std::cout << _map[i] << std::endl;
    _ClearMap();
}

void Map::_ClearMap(void)
{
    for (int i = 0; i < _rowCount; i++)
        for (int j = 0; j < _colCount; j++)
            if (_map[i][j] == 'S') _map[i][j] = ' ';
}

int Map::SetSnake(int x, int y)
{
    if (_map[y][x] == 'S' || _map[y][x] == '#')
        return (1);
    else if (_map[y][x] == 'F') {
        _map[y][x] = 'S';
        _isFruit = 0;
        _SpawnFruit();
        return (2);
    }
    _map[y][x] = 'S';
    return (0);
}

int Map::GetRowCount(void)
{
    return (_rowCount);
}

int Map::GetColCount(void)
{
    return (_colCount);
}

void Map::_SpawnFruit(void)
{
    if (_isFruit == 0) {
        while (1) {
            int x = std::rand() % (_colCount - 2) + 1;
            int y = std::rand() % (_rowCount - 2) + 1;
            if (_map[y][x] != 'S') {
                _map[y][x] = 'F';
                break;
            }
        }
        _isFruit = 1;
    }
}