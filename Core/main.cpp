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

    try {
        Core core(av[1]);
        core.run();
    } catch (std::exception &error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }

    return (0);
}