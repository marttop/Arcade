/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** IGraphicalControl
*/

#ifndef IGRAPHICALCONTROL_HPP_
#define IGRAPHICALCONTROL_HPP_

class IGraphicalControl {
    public:
        enum Scene {
            MENU,
            GAME,
        };

        enum Cell {
            WALL,
            FLOOR,
            GHOST,
        }

        //virtual void displayMenu() const = 0;
        virtual void drawCell() const = 0;

        virtual ~IGraphicalControl() = default;
};

#endif /* !IGRAPHICALCONTROL_HPP_ */