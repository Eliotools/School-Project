/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPrush3-thomas.gillet
** File description:
** info
*/

#ifndef INFO_HPP_
#define INFO_HPP_
#include <string>

class CPU {
    public :
        CPU();
        ~CPU();
        void create();
        std::string getModel();
        std::string getFrequency();
        std::string getNbcore();
        std::string getActivity();
        float reset();
        void printCPU();
    private :
        std::string _model;
        std::string _frequency;
        std::string _nb_cores; 
        std::string _activity;
        float _percent;
};

class RAM {
    public :
        RAM();
        ~RAM();
        void create();
        float getTotal();
        float getFree();
        float getPercent();
        void printRAM();
        float reset();
    private :
        float _total;
        float _free;
        float _percent;
};

class info {
    public:
        info();
        ~info();
        void printAll();
        void setDate();
        void setUsername();
        std::string getHostname();
        std::string getSysname();
        std::string getKernelver();
        std::string getUsername();
        std::string getDate();
        int getLongest();

        RAM getRam() { return _my_ram; }

        CPU getCpu() { return _my_cpu; }

    protected:
    private:
        std::string _hostname;
        std::string _sys_name;
        std::string _kernel_ver;
        std::string _date;
        std::string _username;
        CPU _my_cpu;
        RAM _my_ram;
};

int my_sfml();
int my_ncurse();

#endif /* !INFO_HPP_ */
