/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <iomanip>

class Map {
    public:
        Map();
        ~Map();
        void printMap() const;
        void setScore(int score);
        int getScore() const;
        
        void setFileFromPath(std::string file);
        void _readMap();
        void clearMap();

        std::vector<std::string> map;
    protected:
    private:
        std::ifstream _file;
        int _score;
};

#endif /* !MAP_HPP_ */
