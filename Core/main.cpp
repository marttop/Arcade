/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Using: ./arcade lib" << std::endl;
        return (84);
    }
    Core core(av[1]);

    core.run();
    return (0);
}