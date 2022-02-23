/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** main_ncurses
*/

#include <ncurses.h>
#include <string.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "ModuleGeneral.hpp"
#include "info.hpp"

int my_ncurse()
{
    WINDOW *my_windows;
    ModuleGeneral gen;
    info my_info;
    float act = 0.00;
    std::string acty;
    
    initscr();
    refresh();
    gen.createPrincipalBox(my_windows);
    gen.createPrincipalBoxes();
    gen.writeInfo(my_info);
    gen.writeDataCpu(my_info);
   
    while(1) {
        gen.writeDate(my_info);
        gen.writeRam(my_info);
        gen.writeCpu(my_info);
        
        act = ((stof(my_info.getCpu().getFrequency()) * 100000) / my_info.getCpu().reset()) / 1000;
        acty = std::to_string(act) + "Ghz";
        mvprintw((2 * 8) + 8 - 1+ 3, (50 - acty.size()) / 2, const_cast<char *>(acty.c_str()));

        refresh();
        sleep(1);
    }
    endwin();
    return 0;
}