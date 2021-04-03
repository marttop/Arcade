/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "IGame.hpp"
#include "Key.hpp"
#include <fstream>
#include <unistd.h>

class Menu : public IGame {
    public:
        Menu();
        ~Menu();

        void init(const std::string &map);
        bool update();
        std::map<char, std::string> getTiles() const;
        std::vector<std::string> getMap() const;
        size_t getScore() const;
        void setKeyPressed(Key k);
        void readMap();

    protected:
    private:
        Key _input;
        std::ifstream _file;
        std::vector<std::string> _map;
        size_t _score;
        std::map<char, std::string> _tileMap;
        std::string _games;
        int _gamesIdx;

};

#endif /* !MENU_HPP_ */