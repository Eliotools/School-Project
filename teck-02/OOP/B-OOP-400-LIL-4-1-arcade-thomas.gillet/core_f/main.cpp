/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet [WSL: Ubuntu]
** File description:
** main
*/

#include "../graphic/sfml/sfmldraw.hpp"
#include "../game/nibbler/nibbler.hpp"
#include "../game/centipede/centipede.hpp"
#include "DLLoader.hpp"
#include "Core.hpp"
#include <thread>
#include <chrono>
#include <dlfcn.h>
#include <stdio.h>
#include <ncurses.h>


/*! \mainpage Arcade
 *
 * \section intro_sec Introduction
 *
 * Create your own clone of famous games. Your project should comply with a structure that separates the heart of your game launcher and its graphic dependencies. 
 *
 * \section game_sec Games
 * 
 * Two Games done :
 *  - Nibbler (No wall)
 *  - Centipede (No obstacle)
 * 
 * \section lib_sec Graphics Libs
 * 
 * Three Graphics Libs done :
 *  - SFML (MySfml)
 *  - SDL2 (MySDL2)
 *  - NCurses (MyNcurses)
 *
 * \section command Commands and keys
 * 
 * \subsection game_p Game -> Play
 * 
 * Keys :
 *  - z -> move up
 *  - q -> move left
 *  - s -> move down
 *  - d -> move right
 *  - space -> shoot bullet (Centipede)
 * 
 * \subsection game_l Game -> Other actions
 * 
 * Keys :
 *  - i -> next game
 *  - k -> prev game
 *  - l -> next graphic lib
 *  - j -> previous graphic lib
 *  - a -> quit game and go to menu
 * 
 * \subsection menu Menu -> Commands
 * 
 * Commands :
 *  - start -> launch actual game with actual graphic lib
 *  - exit -> quit menu, close program
 *  - reload -> reload avaible games and graphics lib (in /lib directory)
 *  - lib + "wanted lib" -> set actual lib to wanted lib
 *  - game + "wanted game" -> set actual game to wanted game
 * 
 * \section interface_sharing Interface Sharing
 *  
 *  Interface Sharing with 1 group
 * 
 *  \subsection interface_group Groups
 * 
 *  Julien Delphine (julien.delphine@epitech.eu) and Jules Vitrac (jules.vitrac@epitech.eu)
 *  (Nothing testable)
 * 
 *  \section tech_doc Technical Documentation
 *  Technical Documentation in bonus directory
 *      - latex -> refman.pdf for pdf version
 *      -  html -> index.html for web version
 */

/**
* \brief main
*/
int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    DLLoader loader;
    Core core;
    int playing = 1;

    core.setFirstGame(loader);
    core.setFirstGraph(loader, av[1]);

    core.addPlayerName();
    if (!core.menu(loader))
        return (0);
    while (playing) { 
        if (core.gameLoop(loader) == 1)
            if (!core.menu(loader))
                return (0);
    }
    core.getGraphic()->stop();
    return 0;
}