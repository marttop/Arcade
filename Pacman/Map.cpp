/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
    _file.open("map.txt");
    if (!_file.is_open())
        throw std::invalid_argument("No 'map.txt' found");
    this->_readMap();
}

Map::~Map()
{
}

void Map::Map::_readMap()
{
    std::string line;
    while (getline(this->_file, line)) {
        this->map.push_back(line);
    }
}

void Map::Map::printMap() const
{
    for (std::string s : this->map) {
        std::cout << s << std::endl;
    }
}