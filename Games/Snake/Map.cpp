/*
** EPITECH PROJECT, 2021
** Mini-Snake
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(std::string snakeParts)
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
    _fruits = "FO";
    _fruitValue = 0;
    spawnFruit(snakeParts);
    _file.close();
    _wallParts = "#";
    _score = 0;
}

Map::~Map()
{
}

void Map::freeMap()
{
    while (_map.size() != 0) {
        _map.pop_back();
    }
}

void Map::readMap()
{
    std::string line;
    while (getline(this->_file, line)) {
        this->_map.push_back(line);
    }
}

void Map::setFileFromPath(std::string path)
{
    if (_file.is_open())
        _file.close();
    _file.open(path);
    if (!_file.is_open())
        throw std::invalid_argument("No file found");
}

void Map::clearMap(std::string snakeParts)
{
    for (int i = 0; i < _rowCount; i++)
        for (int j = 0; j < _colCount; j++)
            if (snakeParts.find(_map[i][j]) != std::string::npos) _map[i][j] = ' ';
}

int Map::setSnake(int x, int y, char part, std::string snakeParts)
{
    if (snakeParts.find(_map[y][x]) != std::string::npos || _wallParts.find(_map[y][x]) != std::string::npos)
        return (1);
    else if (_fruits.find(_map[y][x]) != std::string::npos) {
        _map[y][x] = part;
        _score += _fruitValue;
        _isFruit = 0;
        spawnFruit(snakeParts);
        return (2);
    }
    _map[y][x] = part;
    return (0);
}

void Map::setChar(int x, int y, char part)
{
    _map[y][x] = part;
}

int Map::getRowCount(void)
{
    return (_rowCount);
}

int Map::getColCount(void)
{
    return (_colCount);
}

void Map::spawnFruit(std::string snakeParts)
{
    int ret = 0;
    if (_isFruit == 0) {
        while (1) {
            int x = std::rand() % (_colCount - 2) + 1;
            int y = std::rand() % (_rowCount - 2) + 1;
            if (snakeParts.find(_map[y][x]) == std::string::npos && _wallParts.find(_map[y][x]) == std::string::npos) {
                ret = std::rand() % _fruits.size();
                _map[y][x] = _fruits[ret];
                _fruitValue = ret + 1;
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

size_t Map::getScore() const
{
    return (this->_score);
}