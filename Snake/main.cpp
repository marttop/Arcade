/*
** EPITECH PROJECT, 2021
** Mini-Snake
** File description:
** main
*/

#include "Map.hpp"
#include "Utils.hpp"
#include "Player.hpp"
#include "Score.hpp"

int DrawASCIIGame(Player &player, Map &map, int topScore)
{
    std::cout << "\e[1;1H\e[2J";
    if (player.DrawSnake() == 1) {
        WriteTopScore(player.GetScore(), topScore);
        return (1);
    }
    std::cout << "TOP SCORE: " << topScore << std::endl;
    std::cout << "YOUR SCORE: " << player.GetScore() << std::endl << std::endl;
    map.PrintMap();
    return (0);
}

int main(void)
{
    Map map;
    Player player(&map);
    int topScore = GetTopScore();
    DrawASCIIGame(player, map, topScore);
    for (char c = 0; (c = getch()) != 'x';) {
        if (player.MoveSnake(c) == 1)
            if (DrawASCIIGame(player, map, topScore) == 1)
                return (1);
    }
    return (0);
}