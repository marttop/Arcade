/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** SFMLlib
*/

#include "SFMLlib.hpp"

SFMLlib::SFMLlib()
{
}


SFMLlib::~SFMLlib()
{
}

bool SFMLlib::init(const std::string &map, std::map<char, std::string> tileMap)
{
    (void)map;

    _window.create(sf::VideoMode(1920, 1080), "SFML");
    _clock.restart();

    for (auto itr : tileMap) {
        _listText.push_back(new sf::Texture);
        _listText.back()->loadFromFile(itr.second);
        _tileMap.insert(std::make_pair(itr.first, new sf::Sprite));
        _tileMap[itr.first]->setTexture(*_listText.back());
    }

    return (true);
}

void SFMLlib::display(std::vector<std::string> map)
{
    char c;

    _window.clear();

    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            c = map[i][j];
            if (_tileMap[c]) {
                _tileMap[c]->setPosition(sf::Vector2f(j * _tileMap[c]->getTextureRect().width, i * _tileMap[c]->getTextureRect().height));
                _window.draw(*_tileMap[c]);
            }
        }
    }
    _window.display();
}

Key SFMLlib::getKeyPressed()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)  {
            _window.close();
            return (K_EXIT);
        }
        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::Up)
                return (K_UP);
            if (_event.key.code == sf::Keyboard::Down)
                return (K_DOWN);
            if (_event.key.code == sf::Keyboard::Left)
                return (K_LEFT);
            if (_event.key.code == sf::Keyboard::Right)
                return (K_RIGHT);
            if (_clock.getElapsedTime().asSeconds() >= 1) {
                _clock.restart();
                if (_event.key.code == sf::Keyboard::Num1) {
                    _window.close();
                    return (K_PREV_LIB);
                }
                if (_event.key.code == sf::Keyboard::Num2) {
                    _window.close();
                    return (K_NEXT_LIB);
                }
                if (_event.key.code == sf::Keyboard::Num3) {
                    _window.close();
                    return (K_PREV_GAME);
                }
                if (_event.key.code == sf::Keyboard::Num4) {
                    _window.close();
                    return (K_NEXT_GAME);
                }
            }
        }
    }
    return (NONE);
}


void SFMLlib::drawText(size_t x, size_t y, std::string text)
{
    (void)x;
    (void)y;
    (void)text;
}

extern "C" IGfx *createGFX()
{
    return (new SFMLlib);
}

extern "C" void destroyGFX(IGfx *lib)
{
    delete lib;
}