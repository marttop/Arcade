/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** SFMLlib
*/

#include "SFMLlib.hpp"

SFMLlib::SFMLlib()
{
    _window.create(sf::VideoMode(1920, 1080), "Game");
    _window.setFramerateLimit(60);
    _textures[0].loadFromFile("assets/pacmanStrong.png");
    _textures[1].loadFromFile("assets/pacmanWeak.png");
    _textures[2].loadFromFile("assets/wall.png");

}

SFMLlib::~SFMLlib()
{
}

bool SFMLlib::init(const std::string &map)
{
    (void)map;
    for (int i = 0; i < 3; i++) {
        _sprites[i].setTexture(_textures[i]);
    }
}

Key SFMLlib::getKeyPressed()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Up)
                return (K_UP);
            if (_event.key.code == sf::Keyboard::Down)
                return (K_DOWN);
            if (_event.key.code == sf::Keyboard::Left)
                return (K_LEFT);
            if (_event.key.code == sf::Keyboard::Right)
                return (K_RIGHT);
        }
    }
}

void SFMLlib::clear()
{

}

void SFMLlib::drawRect(size_t x, size_t y, Rects entity)
{
    if (entity == WALL) {
        text = IMG_LoadTexture(backGround, "GraphicalLibs/Sources/SDL/bin/wall.jpg");
    } else if (entity == BACKGROUND) {
        text = IMG_LoadTexture(backGround, "GraphicalLibs/Sources/SDL/bin/background.png");
    } else if (entity == PLAYER) {
        text = IMG_LoadTexture(backGround, "GraphicalLibs/Sources/SDL/bin/pacmanStrong.png");
    } else if (entity == ENEMY) {
        text = IMG_LoadTexture(backGround, "GraphicalLibs/Sources/SDL/bin/pacmanWeak.png");
    }
}

void SFMLlib::drawText(size_t x, size_t y, std::string text)
{

}

void SFMLlib::refresh()
{

}

