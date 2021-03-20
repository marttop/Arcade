/*
** EPITECH PROJECT, 2021
** MiniSnake
** File description:
** Player
*/

#include "Player.hpp"
#include "Map.hpp"

Player::Player(Map *map)
{
    _x = map->GetColCount() / 2;
    _y = map->GetRowCount() / 2;
    for (int i = 0; i < 3; i++)
        _snake.push_back(std::make_pair(UP_ARROW, std::make_pair(_x, _y + i)));
    _map = map;
}

Player::~Player()
{
}

void Player::_GrowSnake(void)
{
    _snake.push_back(_snakeEnd);
}

int Player::DrawSnake(void)
{
    int ret = 0;
    int grow = 0;
    for (auto i = _snake.begin(); i != _snake.end(); i++) {
        ret = _map->SetSnake(i->second.first, i->second.second);
        if (ret == 1) return (1);
        if (ret == 2) grow = 1;
    }
    if (grow == 1) {
        _score++;
        _GrowSnake();
    }
    return (0);
}

int Player::GetScore(void)
{
    return (_score);
}

int Player::MoveSnake(char c)
{
    static clock_t currTime = 0;
    static clock_t prevTime = 0;
    if ((c == UP_ARROW || c == LEFT_ARROW || c == RIGHT_ARROW || c == DOWN_ARROW)
    && _snake.size() > 0) {
        if (_snake.begin()->first == UP_ARROW && c == DOWN_ARROW) c = UP_ARROW;
        else if (_snake.begin()->first == DOWN_ARROW && c == UP_ARROW) c = DOWN_ARROW;
        else if (_snake.begin()->first == LEFT_ARROW && c == RIGHT_ARROW) c = LEFT_ARROW;
        else if (_snake.begin()->first == RIGHT_ARROW && c == LEFT_ARROW) c = RIGHT_ARROW;
        _snake.begin()->first = c;
    }
    currTime = clock();
    if (currTime - prevTime >= 100000) {
        _snakeEnd = _snake.back();
        std::pair<int, std::pair<int, int>> snakeHead = std::make_pair(_snake.begin()->first, std::make_pair(_snake.begin()->second.first, _snake.begin()->second.second));
        if (_snake.begin()->first == UP_ARROW) snakeHead.second.second -= 1;
        else if (_snake.begin()->first == DOWN_ARROW) snakeHead.second.second += 1;
        else if (_snake.begin()->first == LEFT_ARROW) snakeHead.second.first -= 1;
        else snakeHead.second.first += 1;
        _snake.insert(_snake.begin(), snakeHead);
        _snake.pop_back();
        prevTime = currTime;
        return (1);
    }
    return (0);
}