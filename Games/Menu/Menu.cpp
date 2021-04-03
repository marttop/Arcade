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
}

void Menu::init(const std::string &map)
{
    (void)map;
    _file.open("db/db_Menu/menu.txt");
    if (!_file.is_open())
        throw std::invalid_argument("No 'menu.txt' found");
    this->readMap();
}

void Menu::readMap()
{
    std::string line;
    while (getline(this->_file, line)) {
        this->_map.push_back(line);
    }
}

bool Menu::update()
{
    return (true);
}

std::map<char, std::string> Menu::getTiles() const
{
    std::map<char, std::string> tileMap;
    std::ifstream file;
    std::string line;
    file.open("db/db_Menu/config.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            tileMap.insert(std::make_pair(
                line[line.find('=') + 1],
                line.substr(0, line.find('='))
            ));
        }
        file.close();
    }

    return (tileMap);
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