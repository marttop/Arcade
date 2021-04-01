/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** CtrlSFML
*/

#ifndef CTRLSFML_HPP_
#define CTRLSFML_HPP_

#include <iostream>
#include "../Interface/IGraphicalControl.hpp"
#include "SFML/Graphics.hpp"

class CtrlSFML : public IGraphicalControl {
    public:
        CtrlSFML();
        ~CtrlSFML();

        template <typename T>
        void CtrlSFML::drawCell(int x, int y, T type) const;

    protected:
    private:
        sf::RenderWindow *_window;
        sf::RectangleShape *_cell;
};

#endif /* !CTRLSFML_HPP_ */