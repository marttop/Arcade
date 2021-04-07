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
    std::ifstream file;
    std::string line;
    file.open("db/db_Pacman/score.txt");
    if (file.is_open())
        getline(file, line);
    this->_bestPacman = std::atoi(line.c_str());
    file.close();
    file.open("db/db_Snake/score.txt");
    if (file.is_open())
        getline(file, line);
    this->_bestSnake = std::atoi(line.c_str());
    file.close();
    getNameFromFile();
}

Menu::~Menu()
{
    _file.close();
    setNameToFile();
}

size_t Menu::getBestScore() const
{
    if (_gamesIdx == 0)
        return (this->_bestPacman);
    else
        return (this->_bestSnake);
}

void Menu::getNameFromFile()
{
    std::ifstream file;
    std::string line;
    file.open("db/db_Menu/name.txt");
    if (file.is_open()) {
        getline(file, line);
        this->_name = line;
        file.close();
    }
}

void Menu::setNameToFile()
{
    std::ofstream file;
    file.open("db/db_Menu/name.txt");
    if (file.is_open()) {
        file.clear();
        file << this->_name;
    }
    file.close();
}

void Menu::init()
{
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

bool Menu::update()
{
    if (_input == K_LEFT) {
            _gamesIdx--;
            if (_gamesIdx < 0) _gamesIdx = (int)_games.size() - 1;
    }
    else if (_input == K_RIGHT) {
        _gamesIdx++;
        if (_gamesIdx > (int)_games.size() - 1) _gamesIdx = 0;
    }
    if (_input == K_SPACE)
        return (true);
    return (false);
}

std::string Menu::getName() const
{
    return (this->_name);
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
    if (isalpha(k)) {
        this->_name = this->_name + (char)k;
    }
    else if (k == K_DEL) {
        this->_name = this->_name.substr(0, this->_name.size() - 1);
    }
}

extern "C" IGame *createGame()
{
    return (new Menu);
}

extern "C" void destroyGame(IGame *game)
{
    delete game;
}