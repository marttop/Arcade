/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** NcursesLib
*/

#ifndef NCURSESLIB_HPP_
#define NCURSESLIB_HPP_

#include "IGfx.hpp"

class NcursesLib : public IGfx {
    public:
        NcursesLib();
        ~NcursesLib();

        bool init(const std::string &map, std::map<char, std::string>);
        Key getKeyPressed();
        void drawText(size_t x, size_t y, std::string text, size_t size);
        void draw(std::vector<std::string>);
        void clear();
        void display();
    protected:
    private:
};

#endif /* !NCURSESLIB_HPP_ */
