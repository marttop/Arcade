/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Key
*/

#ifndef KEY_HPP
#define KEY_HPP

typedef enum Key
{
    K_LEFT = 0,
    K_RIGHT,
    K_UP,
    K_DOWN,
    K_SPACE,
    K_ESC,
    K_EXIT,
    NONE,
} Key;

typedef enum Rects
{
    WALL,
    PACMAN,
    SNAKE_HEAD,
    SNAKE,
    GHOST,
    FRUIT,
    GUM,
    BUTTON,
    BACKGROUND,
} Rects;

#endif