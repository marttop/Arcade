/*
** EPITECH PROJECT, 2021
** MiniSnake
** File description:
** Score
*/

#include "Score.hpp"

int GetTopScore(void)
{
    std::fstream file;
    file.open("top_score");
    if (!file.is_open()) {
        std::cerr << "Could not open 'top_score'" << std::endl;
        exit (84);
    }
    std::string line;
    std::getline(file, line);
    file.close();
    int topScore = std::atoi(line.c_str());
    if (topScore < 0) topScore = 0;
    return (topScore);
}

void WriteTopScore(int score, int topScore)
{
    std::fstream file;
    file.open("top_score");
    if (!file.is_open()) {
        std::cerr << "Could not open 'top_score'" << std::endl;
        exit (84);
    }
    if (score > topScore) file << score;
    file.close();
}