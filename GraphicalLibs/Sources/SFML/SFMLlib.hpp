/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** SFMLlib
*/

#ifndef SFMLLIB_HPP_
#define SFMLLIB_HPP_

#include "IGfx.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>

class SFMLlib : public IGfx {
    public:
        SFMLlib();
        ~SFMLlib();

        bool init(const std::string &map, std::map<char, std::string>);
        void display(std::vector<std::string>);
        Key getKeyPressed();
        void drawText(size_t x, size_t y, std::string text);

    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        std::vector<sf::Texture *> _listText;
        std::map<char, sf::Sprite *> _tileMap;

};

#endif /* !SFMLLIB_HPP_ */
