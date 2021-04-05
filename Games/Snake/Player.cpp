/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Player
*/

#include "Player.hpp"
#include "Map.hpp"

Player::Player()
{
    _map = new Map;
    _x = _map->getColCount() / 2;
    _y = _map->getRowCount() / 2;
    for (int i = 0; i < 3; i++)
        _snake.push_back(std::make_pair(K_UP, std::make_pair(_x, _y + i)));
    _score = 0;
    this->getScoreFromFile();
}

Player::~Player()
{
    delete _map;
    this->setScoreToFile();
}

void Player::getScoreFromFile()
{
    std::ifstream file;
    std::string line;
    file.open("db/db_Snake/score.txt");
    if (file.is_open())
        getline(file, line);
    this->_bestScore = std::atoi(line.c_str());
}

void Player::setScoreToFile()
{
    if (this->_score > this->_bestScore) {
        std::ofstream file;
        file.open("db/db_Snake/score.txt");
        if (file.is_open())
            file << std::to_string(this->_score);
    }
}

size_t Player::getBestScore() const
{
    return (_bestScore);
}

void Player::growSnake(void)
{
    _snake.push_back(_snakeEnd);
}

int Player::drawSnake(void)
{
    int ret = 0;
    int grow = 0;

    _map->clearMap();
    for (auto i = _snake.begin(); i != _snake.end(); i++) {
        ret = _map->setSnake(i->second.first, i->second.second);
        if (ret == 1) return (1);
        if (ret == 2) grow = 1;
    }
    if (grow == 1) {
        _score++;
        growSnake();
    }
    return (0);
}

void Player::init()
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

bool Player::update()
{
    static std::chrono::_V2::system_clock::time_point currTime = my_clock::now();
    static std::chrono::_V2::system_clock::time_point prevTime = my_clock::now();
    currTime = my_clock::now();
    static char cBuf = NONE;

    if (this->drawSnake()) {
        this->setScoreToFile();
        exit(0);
    }
    if ((this->_input == K_UP || this->_input == K_LEFT || this->_input == K_RIGHT || this->_input == K_DOWN) && _snake.size() > 0) {
        if (_snake.begin()->first == K_UP && this->_input == K_DOWN) this->_input = K_UP;
        else if (_snake.begin()->first == K_DOWN && this->_input == K_UP) this->_input = K_DOWN;
        else if (_snake.begin()->first == K_LEFT && this->_input == K_RIGHT) this->_input = K_LEFT;
        else if (_snake.begin()->first == K_RIGHT && this->_input == K_LEFT) this->_input = K_RIGHT;
        cBuf = this->_input;
    }
    if (std::chrono::duration_cast<std::chrono::microseconds>(currTime - prevTime).count() >= 70000) {
        if (cBuf != NONE) _snake.begin()->first = cBuf;
        _snakeEnd = _snake.back();
        std::pair<int, std::pair<int, int>> snakeHead = std::make_pair(_snake.begin()->first, std::make_pair(_snake.begin()->second.first, _snake.begin()->second.second));
        if (_snake.begin()->first == K_UP) snakeHead.second.second -= 1;
        else if (_snake.begin()->first == K_DOWN) snakeHead.second.second += 1;
        else if (_snake.begin()->first == K_LEFT) snakeHead.second.first -= 1;
        else snakeHead.second.first += 1;
        _snake.insert(_snake.begin(), snakeHead);
        _snake.pop_back();
        prevTime = currTime;
        cBuf = NONE;
    }

    if (_input == K_SPACE)
        return (true);
    return (false);
}

void Player::setKeyPressed(Key k)
{
    this->_input = k;
}

std::vector<std::string> Player::getMap() const
{
    return (_map->getMap());
}

size_t Player::getScore() const
{
    return (this->_score);
}

std::map<char, std::string> Player::getTiles() const
{
    std::map<char, std::string> tileMap;
    std::ifstream file;
    std::string line;
    file.open("db/db_Snake/config.txt");
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

std::string Player::getName() const
{
    return (_name);
}

extern "C" IGame *createGame()
{
    return (new Player);
}

extern "C" void destroyGame(IGame *game)
{
    delete game;
}