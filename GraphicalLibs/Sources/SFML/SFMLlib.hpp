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

        bool init(const std::string &map);
        Key getKeyPressed();
        void clear();
        void drawRect(size_t x, size_t y, Rects fion);
        void drawText(size_t x, size_t y, std::string text);
        void refresh();

    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Texture _textures[3];
        sf::Sprite _sprites[3];

};

#endif /* !SFMLLIB_HPP_ */
