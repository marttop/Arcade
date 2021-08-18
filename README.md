# Arcade
* binary name: **arcade**
* language: **C++**
* compilation: via **Makefile** (all, clean, fclean, re) or **CMake** *3.17*

## Description
Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of
player scores.
To be able to deal with the elements of your gaming plateform at run-time, your graphics libraries and your games
must be implemented as dynamic libraries, loaded at runtime.
Each GUI available for the program must be used as a shared
library that will be loaded and used dynamically by the main
program.

## Dynamic libraries
You must use dynamic libraries at run-time.
This means that you MUST use the ```dlopen```, ```dlclose```, ```dlsym``` and ```dlerror``` functions to handle your dynamic
libraries.

These dynamic libraries can be seen as plug-ins providing various capabilities to your main program.
In NO CASE must graphics libraries influence the game logic.
Game libraries must not contain any information about screen rendering or low-level events.
Your libraries (games and graphics) binaries (*.so) must be placed in the ./lib/ directory at the root of your
repository.

## Graphics libraries
You must implement the nCurses (arcade_ncurses.so) and SDL2 (arcade_sdl2.so) graphical libraries, and at
least one more from the following list:
* NDK++ (arcade_ndk++.so)
* aa-lib (arcade_aalib.so)
* libcaca (arcade_libcaca.so)
* Allegro5 (arcade_allegro5.so)
* Xlib (arcade_xlib.so)
* GTK+ (arcade_gtk+.so)
* SFML (arcade_sfml.so)
* Irrlicht (arcade_irrlicht.so)
* OpenGL (arcade_opengl.so)
* Vulkan (arcade_vulkan.so)
* Qt5 (arcade_qt5.so)

## Game libraries
You must implement at least two games from the following list:
* Nibbler (arcade_nibbler.so)
* Pacman (arcade_pacman.so)
* Qix (arcade_qix.so)
* Centipede (arcade_centipede.so)
* Solarfox (arcade_solarfox.so)

## Build & Usage

The Makefile have the following rules (in addition to all, re, clean and fclean):
* core: it only builds the core of your arcade (not the games nor the graphical librairies).
* games: it only builds your games librairies.
* graphicals: it only builds your graphical librairies.

The results of running a simple make command in your turn in directory generates a program, at least
three graphics dynamic libraries and at least two game dynamic libraries.

The program takes as a startup argument the graphics library to use initially ```$ ./arcade ./lib/arcade_ncurses.so```.
It is possible to change the graphics library at run-time.

### Other
To install the SDL_image package on fedora:

     sudo dnf install SDL2_image SDL2_image-devel SDL2_ttf SDL2_ttf-devel
