/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** CtrlSFML
*/

#include "CtrlSFML.hpp"

CtrlSFML::CtrlSFML()
{
    _window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML");
    _window->setFramerateLimit(60);
    _cell = new sf::RectangleShape(sf::Vector2f{100, 100});
}

CtrlSFML::~CtrlSFML()
{
}

template <typename T>
void CtrlSFML::drawCell(int x, int y, Cell type) const
{
    if (type == WALL)

}