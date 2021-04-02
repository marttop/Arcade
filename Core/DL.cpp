/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** DL
*/

#include "DL.hpp"

DL::DL()
{
}

DL::~DL()
{
}

std::string DL::error()
{
    return (dlerror());
}

void DL::open(char *filepath, int flag)
{
    _cheddar = dlopen(filepath, flag);
    std::cout << "de la merde" << std::endl;
    if (!_cheddar) {
        throw std::invalid_argument(this->error());
    }
}

int DL::close()
{
   return (dlclose(_cheddar));
}

void *DL::sym(std::string name)
{
    return (dlsym(_cheddar, name.c_str()));
}
