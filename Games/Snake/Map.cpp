/*
** EPITECH PROJECT, 2021
** Mini-Snake
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
    _rowCount = 0;
    _colCount = 0;
    std::srand(std::time(0));
    _file.open("db/db_Snake/map.txt");
    if (!_file.is_open())
        throw std::invalid_argument("No 'map.txt' found");
    this->readMap();
    _rowCount = _map.size();
    _colCount = _map[0].size();
    _isFruit = 0;
    spawnFruit();
    _file.close();
}

Map::~Map()
{
}

void Map::readMap()
{
    std::string line;
    while (getline(this->_file, line)) {
        this->_map.push_back(line);
    }
}

void Map::clearMap(void)
{
    for (int i = 0; i < _rowCount; i++)
        for (int j = 0; j < _colCount; j++)
            if (_map[i][j] == 'S') _map[i][j] = ' ';
}

int Map::setSnake(int x, int y)
{
    if (_map[y][x] == 'S' || _map[y][x] == '#')
        return (1);
    else if (_map[y][x] == 'F') {
        _map[y][x] = 'S';
        _isFruit = 0;
        spawnFruit();
        return (2);
    }
    _map[y][x] = 'S';
    return (0);
}

int Map::getRowCount(void)
{
    return (_rowCount);
}

int Map::getColCount(void)
{
    return (_colCount);
}

void Map::spawnFruit(void)
{
    if (_isFruit == 0) {
        while (1) {
            int x = std::rand() % (_colCount - 2) + 1;
            int y = std::rand() % (_rowCount - 2) + 1;
            if (_map[y][x] != 'S' && _map[y][x] != '#') {
                _map[y][x] = 'F';
                break;
            }
        }
        _isFruit = 1;
    }
}

std::vector<std::string> Map::getMap() const
{
    return (this->_map);
}