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
    createMap();
}

Map::~Map()
{
    for (int i = 0; i < _rowCount; i++)
        delete []_map[i];
    delete []_map;
}

void Map::createMap(void)
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
    spawnFruit();
}

void Map::printMap(void)
{
    for (int i = 0; i < _rowCount; i++)
        std::cout << _map[i] << std::endl;
    clearMap();
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
            if (_map[y][x] != 'S') {
                _map[y][x] = 'F';
                break;
            }
        }
        _isFruit = 1;
    }
}

int Map::drawAsciiGame(Player &player, int topScore)
{
    std::cout << "\e[1;1H\e[2J";
    if (player.drawSnake() == 1) {
        WriteTopScore(player.getScore(), topScore);
        return (1);
    }
    std::cout << "TOP SCORE: " << topScore << std::endl;
    std::cout << "YOUR SCORE: " << player.getScore() << std::endl << std::endl;
    printMap();
    return (0);
}