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

int main(void)
{
    Map map;
    Player player(&map);
    int topScore = GetTopScore();
    map.drawAsciiGame(player, topScore);
    for (char c = 0; (c = getch()) != 'x';) {
        if (player.moveSnake(c) == 1)
            if (map.drawAsciiGame(player, topScore) == 1)
                return (1);
    }
    return (0);
}