/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
    _file.open("db/db_Pacman/map.txt");
    if (!_file.is_open())
        throw std::invalid_argument("No 'map.txt' found");
    this->_readMap();
    this->_score = 0;
    _file.close();
}

Map::~Map()
{
    if (_file.is_open())
        _file.close();
}

void Map::clearMap()
{
    while (map.size() != 0) {
        map.pop_back();
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

void Map::_readMap()
{
    std::string line;
    while (getline(this->_file, line)) {
        this->map.push_back(line);
    }
}

void Map::printMap() const
{
    for (std::string s : this->map) {
        std::cout << s << std::endl;
    }
}

int Map::getScore() const
{
    return (this->_score);
}

void Map::setScore(int score)
{
    this->_score = score;
}