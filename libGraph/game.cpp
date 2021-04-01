/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** game test hpp
*/

#include "game.hpp"

#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <poll.h>

Game::Game()
{
}

void Game::init(IGfx *gfx, const std::string &nth)
{
    std::string line;
    std::ifstream file;

    file.open("map.txt");
    while (getline(file, line)) {
        this->_map.push_back(line);
    }
    _gfx = gfx;
}

void Game::parser() const
{
    int x = 0;
    int y = 0;
    for (std::string line : _map) {
        for(std::string::size_type i = 0; i < line.length(); ++i) {
            char c = line[i];
            if (c == 'G') {
                _gfx->drawRect(x, y, ENEMY);
            } else if (c == '#') {
                _gfx->drawRect(x, y, WALL);
            } else if (c == '@') {
                _gfx->drawRect(x, y, PLAYER);
            } else {
                _gfx->drawRect(x, y, BACKGROUND);
            }
            x += 25;
        }
        x = 0;
        y += 25;
    }
}

void Game::run()
{
    while (_gfx && _gfx->getKeyPressed() != Key::K_EXIT) {
        display();
    }
}

void Game::display() const
{
    if (_gfx) {
        _gfx->clear();
        // _gfx->drawRect(40, 20, WALL);
        parser();
        _gfx->refresh();
    } else {
        for (std::string str : _map)
            std::cout << str << std::endl;
        std::cout << "--" << std::endl;
    }
}