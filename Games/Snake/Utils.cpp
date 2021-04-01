/*
** EPITECH PROJECT, 2021
** MiniSnake
** File description:
** Utils
*/

#include "Utils.hpp"

char getch(void)
{
    char buf = 0;
    struct termios old;
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    struct pollfd fds[1] = {0, POLLIN, 0};
    int timeout_msecs = 0;
    if (poll(fds, 1, timeout_msecs) > 0)
        if (read(0, &buf, 1) < 0) perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror ("tcsetattr ~ICANON");
    return (buf);
}