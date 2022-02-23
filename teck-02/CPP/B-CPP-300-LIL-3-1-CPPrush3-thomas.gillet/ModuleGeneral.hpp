/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** ModuleGeneral
*/

#ifndef MODULEGENERAL_HPP_
#define MODULEGENERAL_HPP_
#include "Box.hpp"
#include <vector>
#include "IMonitor.hpp"

class ModuleGeneral : public IMonitorModule, public IMonitorDisplay 
{
    public:
        ModuleGeneral();
        ~ModuleGeneral();
        void createPrincipalBox(WINDOW *win);
        std::vector<Box> getBoxes();
        Box createBox();
        Box createBoxCPU();
        void createPrincipalBoxes();
        void writeInfo(info &my_info);
        void writeDate(info &my_info);
        void writeRam(info &my_info);
        void writeCpu(info &my_info);
        void writeDataCpu(info &my_info);

    protected:
    private:
        std::vector<Box> _boxes;
};

#endif /* !MODULEGENERAL_HPP_ */
