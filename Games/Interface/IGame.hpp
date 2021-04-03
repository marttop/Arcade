/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>
#include <vector>
#include <map>
#include "Key.hpp"

class IGame {
    public:
        virtual ~IGame(){};
        virtual void init(const std::string &map) = 0;
        virtual bool update() = 0;

        virtual std::map<char, std::string> getTiles() const = 0;
        virtual std::vector<std::string> getMap() const = 0;
        virtual size_t getScore() const = 0;
        virtual std::string getName() const = 0;

        virtual void setKeyPressed(Key k) = 0;
};

#endif /* !IGAME_HPP_ */
