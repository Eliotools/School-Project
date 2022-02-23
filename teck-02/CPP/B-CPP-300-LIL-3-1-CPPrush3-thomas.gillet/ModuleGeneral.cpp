/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** ModuleGeneral
*/

#include "ModuleGeneral.hpp"
#include "Box.hpp"
#include "info.hpp"
#include <string.h>

ModuleGeneral::ModuleGeneral() : IMonitorModule(), IMonitorDisplay()
{
}

ModuleGeneral::~ModuleGeneral()
{
}

void ModuleGeneral::createPrincipalBox(WINDOW *win)
{
    Box tmp(LINES, 52, 0, 0, "Principal");

    _boxes.push_back(tmp);
    win = tmp.create_box();
}

std::vector<Box> ModuleGeneral::getBoxes()
{
    return _boxes;
}

Box ModuleGeneral::createBox()
{
    static int i = 1;
    Box tmp(3, 50, i * 3 - 2, 1, "Principal");

    tmp.create_box();
    i++;
    return tmp;
}

Box ModuleGeneral::createBoxCPU()
{
    static int i = 8;
    Box tmp(2 + 4, 50, i * 3 - 2, 1, "Principal");

    tmp.create_box();
    i++;
    return tmp;
}

void ModuleGeneral::createPrincipalBoxes()
{
    getBoxes().push_back(createBox());
    getBoxes().push_back(createBox());
    getBoxes().push_back(createBox());
    getBoxes().push_back(createBox());
    getBoxes().push_back(createBox());
    getBoxes().push_back(createBox());
    getBoxes().push_back(createBox());
    getBoxes().push_back(createBoxCPU());
}

void ModuleGeneral::writeInfo(info &my_info)
{
    std::vector<Box>::iterator it = getBoxes().begin();

    it++;
    for (int i = 1; i < 5; i++){
        if (i == 1)
            mvprintw((2 * i) + i - 1, (50 - my_info.getUsername().size()) / 2, const_cast<char *>(my_info.getUsername().c_str()));
        if (i == 2)
            mvprintw((2 * i) + i - 1, (50 - my_info.getHostname().size()) / 2, const_cast<char *>(my_info.getHostname().c_str()));
        if (i == 3)
            mvprintw((2 * i) + i - 1, (50 - my_info.getSysname().size()) / 2, const_cast<char *>(my_info.getSysname().c_str()));
        if (i == 4)
            mvprintw((2 * i) + i - 1, (50 - my_info.getKernelver().size()) / 2, const_cast<char *>(my_info.getKernelver().c_str()));
        it++;
    }
}

void ModuleGeneral::writeDate(info &my_info)
{
    std::vector<Box>::iterator it = getBoxes().begin();
    int i = 0;
    my_info.setDate();

    for (i = 1; i < 5; i++);
    mvprintw((2 * i) + i - 1, (50 - my_info.getDate().size()) / 2, const_cast<char *>(my_info.getDate().c_str()));
}

void ModuleGeneral::writeRam(info &my_info)
{
    std::vector<Box>::iterator it = getBoxes().begin();
    int i = 0;
    my_info.setDate();

    for (i = 1; i < 6; i++);
    int tmp = (int)my_info.getRam().reset();
    mvprintw((2 * i) + i - 1, 2, "RAM:");
    for (int j = 0; j < 44; j++)
        mvprintw((2 * i) + i - 1, j + 6, " ");
    for (int j = 0; j < (tmp * 44)/100; j++)
        mvprintw((2 * i) + i - 1, j + 6, "#");
    mvprintw((2 * i) + i - 1, 48, std::to_string(tmp).c_str());
}

void ModuleGeneral::writeCpu(info &my_info)
{
    std::vector<Box>::iterator it = getBoxes().begin();
    int i = 0;
    my_info.setDate();

    for (i = 1; i < 7; i++);
    int tmp = (int)my_info.getCpu().reset();
    mvprintw((2 * i) + i - 1, 2, "CPU:");
    for (int j = 0; j < 44; j++)
        mvprintw((2 * i) + i - 1, j + 6, " ");
    for (int j = 0; j < (tmp * 44)/100; j++)
            if (j < 44)
                mvprintw((2 * i) + i - 1, j + 6, "#");
    mvprintw((2 * i) + i - 1, 48, std::to_string(tmp).c_str());
}

void ModuleGeneral::writeDataCpu(info &my_info)
{
    int i = 0;
    for (i = 1; i < 8; i++);
    std::string model = my_info.getCpu().getModel();
    mvprintw((2 * i) + i - 1, (50 - model.size()) / 2, (char *)model.c_str());
    mvprintw((2 * i) + i - 1 + 1, (50 - my_info.getCpu().getFrequency().size()) / 2, const_cast<char *>(my_info.getCpu().getFrequency().c_str()));
    mvprintw((2 * i) + i - 1 + 2, (50 - my_info.getCpu().getNbcore().size()) / 2, const_cast<char *>(my_info.getCpu().getNbcore().c_str()));
}