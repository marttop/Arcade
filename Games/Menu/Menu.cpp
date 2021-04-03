/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    _score = 0;
}

Menu::~Menu()
{
    _file.close();
}

void Menu::init(const std::string &map)
{
    (void)map;
    _file.open("db/db_Menu/menu.txt");
    if (!_file.is_open())
        throw std::invalid_argument("No 'menu.txt' found");
    this->readMap();

    std::ifstream file;
    std::string line;
    file.open("db/db_Menu/config.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            _tileMap.insert(std::make_pair(
                line[line.find('=') + 1],
                line.substr(0, line.find('='))
            ));
        }
        file.close();
    }
    _games = "@S";
    _gamesIdx = 0;
}

void Menu::readMap()
{
    std::string line;
    while (getline(this->_file, line)) {
        this->_map.push_back(line);
    }
}

#include <fstream>

bool Menu::update()
{
    if (_input == K_LEFT) {
        for (size_t i = 0, j = 0; i < _map.size(); i++) {
            if ((j = _map[i].find(_games[_gamesIdx])) != std::string::npos) {
                _gamesIdx--;
                if (_gamesIdx < 0) _gamesIdx = (int)_games.size() - 1;
                _map[i][j] = _games[_gamesIdx];
                break;
            }
        }
    }
    else if (_input == K_RIGHT) {
        for (size_t i = 0, j = 0; i < _map.size(); i++) {
            if ((j = _map[i].find(_games[_gamesIdx])) != std::string::npos) {
                _gamesIdx++;
                if (_gamesIdx > (int)_games.size() - 1) _gamesIdx = 0;
                _map[i][j] = _games[_gamesIdx];
                break;
            }
        }
    }
    if (_input == K_SPACE)
        return (true);
    return (false);
}

std::map<char, std::string> Menu::getTiles() const
{
    return (_tileMap);
}

std::vector<std::string> Menu::getMap() const
{
    return (_map);
}

size_t Menu::getScore() const
{
    return (this->_score);
}

void Menu::setKeyPressed(Key k)
{
    this->_input = k;
}

extern "C" IGame *createGame()
{
    return (new Menu);
}

extern "C" void destroyGame(IGame *game)
{
    delete game;
}