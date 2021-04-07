/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** NcursesLib
*/

#include "NcursesLib.hpp"

NcursesLib::NcursesLib()
{

}

NcursesLib::~NcursesLib()
{

}

bool NcursesLib::init(const std::string &map, std::map<char, std::string>)
{
    (void)map;
    initscr();
    raw();
    nodelay(stdscr, true);
    curs_set(0);
    noecho();
    keypad(stdscr, true);
    _window = newwin(1080, 1920, 0, 0);
}

#include <iostream>

Key NcursesLib::getKeyPressed()
{
    int c = getch();
    if (isalpha(c)) {
        return ((Key)c);
    }
    if (c == KEY_UP)
        return (K_UP);
    if (c == KEY_DOWN)
        return (K_DOWN);
    if (c == KEY_LEFT)
        return (K_LEFT);
    if (c == KEY_RIGHT)
        return (K_RIGHT);
    if (c == 38)
        return (K_PREV_LIB);
    if (c == 169)
        return (K_NEXT_LIB);
    if (c == 34)
        return (K_PREV_GAME);
    if (c == 39)
        return (K_NEXT_GAME);
    if (c == ' ')
        return (K_SPACE);
    if (c == KEY_BACKSPACE)
        return (K_DEL);
    if (c == 27) {
        this->clear();
        delwin(_window);
        printf("\e[1;1H\e[2J");
        return (K_EXIT);
    }
    return (NONE);
}

void NcursesLib::drawText(size_t x, size_t y, std::string text, size_t size)
{

}

void NcursesLib::draw(std::vector<std::string> map)
{
    int i = 0;
    for (auto itr : map) {
        mvwprintw(_window, i, 0, itr.c_str());
        i++;
    }
}

void NcursesLib::clear()
{
    werase(_window);
}

void NcursesLib::display()
{
    wrefresh(_window);
}

extern "C" IGfx *createGFX()
{
    return (new NcursesLib);
}

extern "C" void destroyGFX(IGfx *lib)
{
    delete lib;
}
