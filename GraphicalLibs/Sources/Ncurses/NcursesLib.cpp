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
    return (true);
}

Key NcursesLib::getKeyPressed()
{
    return ((Key)1);
}

void NcursesLib::drawText(size_t x, size_t y, std::string text, size_t size)
{

}

void NcursesLib::draw(std::vector<std::string>)
{

}

void NcursesLib::clear()
{

}

void NcursesLib::display()
{

}

extern "C" IGfx *createGFX()
{
    return (new NcursesLib);
}

extern "C" void destroyGFX(IGfx *lib)
{
    delete lib;
}
