/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** IGameControl
*/

#ifndef IGAMECONTROL_HPP_
#define IGAMECONTROL_HPP_

class IGameControl {
    public:
        enum Scene {
            MENU,
            GAME,
        };

        virtual void displayMap() const = 0;

        virtual ~IGameControl() = default;
};

#endif /* !IGAMECONTROL_HPP_ */