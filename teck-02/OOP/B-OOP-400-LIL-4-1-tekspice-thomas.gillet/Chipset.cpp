/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** chipset
*/

#include "Chipset.hpp"
#include "And_4081.hpp"


Component::Component() 
{
}

Component::~Component()
{

}

void Component::createMap(std::string file, std::string gate)
{
    int my_switch = 0;
    int pos = 0;
    int nb = 1, i = 1;
    std::string tmp;
    std::ifstream myfile (file);
    std::string name;
    while (getline (myfile, tmp)) {
        if(!tmp.compare(".links:")) {
            my_switch = 1;
            continue;
        }
        if (my_switch == 1) {
            pos = tmp.find(':');
            if (!(pos < 0)) {
                name = tmp.substr(0, pos);
                if (name == gate) {
                    name = tmp.substr(tmp.find(' ')+1);
                    name = name.substr(0, name.find(':'));
                }
                tmp = tmp.substr(pos+1);
                pos = tmp.find(':');
                if (!(pos < 0)) {
                   tmp = tmp.substr(pos+1);
                }
                pos = std::stoul(tmp);
                i = 1;
                for (auto &it: _pins) {
                    if (i == nb) {
                        it.second.name = name;
                        break;
                    }
                    ++i;
                }
                nb+=1;
            }
        }
    }
    myfile.close();    
}

std::vector<int> Component::createIntVector(int one, int two)
{
    std::vector<int> tab;
    tab.push_back(one);
    tab.push_back(two);
    return tab;
}

void Component::simulate()
{
    makeItWork();
    mouvState();
}

void Component::dump()
{
    printMap(true);
}

pinData *Component::getPin(int i)
{
    return (&_pins[i]);
}

std::map<int,pinData> Component::getMap()
{
    return (_pins);
}

pinData Component::createStruc(nts::Tristate states, std::vector<int> in, int out, std::string g_name, int places)
{
    pinData pin;
    pin.name = g_name;
    pin.state = states;
    pin.pin_in = in;
    pin.pin_out = out;
    pin.place = places;
    return (pin);
}

void Component::addInMap(pinData struc)
{
    static int i = 1;
    _pins.insert(std::pair<int, pinData>(i, struc));
    i++;
}

void Component::printList(std::vector<int> const &list)
{
    for (auto const& i: list) {
        if (i < 10)
            std::cout << "0";
        std::cout << i << " ";
    }
}

void Component::printMap(bool hint)
{
    int i = 1;
    if (hint == true) {
            std::cout << "\033[1;34mPair->first\033[1;0m{ | \033[1;35mPair->second->name\033[1;0m| | \033[1;31mPair->second->state\033[1;0m | | \033[1;33mPair->second->pin_in\033[1;0m| |\033[1;32mPair->second->pin_out\033[1;0mPair->second->place" << std::endl;
        }
    for (auto const& pair : _pins) {
        std::cout << "\033[1;34mPin " << pair.first << "\t\033[1;0m{ | \033[1;35mName: " << pair.second.name << " \033[1;0m|\t| \033[1;31mValue : " << pair.second.state << "\033[1;0m |\t| \033[1;33mLink_in : ";
        printList(pair.second.pin_in);
        std::cout << " \033[1;0m|\t|\033[1;32m Link_out : ";
        if (pair.second.pin_out < 10)
            std::cout << "0";
        std::cout << pair.second.pin_out << "\t\033[1;0m|\t\033[1;38m" <<pair.second.place << " \033[1;0m}" << std::endl;
        i++;
    }
}

void Component::setState(pinData *pin, nts::Tristate new_state)
{
    pin->state = new_state;
}

int Component::getState(pinData *pin)
{
    if (pin->state == nts::FALSE)
        return (0);
    if (pin->state == nts::TRUE)
        return (1);
    return (-1);
}

int Component::getStateSim(pinData *pin)
{
    if (pin->stateSim == nts::FALSE)
        return (0);
    if (pin->stateSim == nts::TRUE)
        return (1);
    return (-1);
}

pinData *Component::getPinByName(std::string name)
{
    int i = 1;
    for (auto pair = _pins.cbegin(); pair != _pins.cend(); ++pair, ++i)
    {
        if ((*pair).second.name == name) {
            return (&_pins[i]);
        }
    }
    return nullptr;
}

nts::Tristate Component::intToTristate(int i)
{
    if (i == 0)
        return (nts::FALSE);
    if (i == 1)
        return (nts::TRUE);
    return (nts::UNDEFINED);
}

void Component::displayAll()
{
    int i = 1;
    std::cout << "input(s):" << std::endl;
    for (auto pair = _pins.cbegin(); pair != _pins.cend(); ++pair) {
        if (pair->second.place == 0 && pair->second.name != "default")
            std::cout << "\t" << pair->second.name << ": " << getStateSim(getPin(i)) << std::endl;
        ++i;
    }
    i = 1;
    std::cout << "output(s):" << std::endl;
    for (auto pair = _pins.cbegin(); pair != _pins.cend(); ++pair) {
        if (pair->second.place == 1 && pair->second.name != "default")
            std::cout << "\t" << pair->second.name << ": " << getStateSim(getPin(i)) << std::endl;
        ++i;
    }
}

void Component::mouvState()
{
    int i = 1;
    while (i != getNbPin()+1)
    {
        setStateSim(getPin(i), (getPin(i))->state);
        i++;
    }
}

int Component::getNbPin()
{
    int i = 0;
    for (auto pair = _pins.cbegin(); pair != _pins.cend(); ++pair)
        if ((*pair).second.name != "default")
            i++;
    return i;
}

void Component::setStateSim(pinData *pin, nts::Tristate stat)
{
    pin->stateSim = stat;
}

void Component::makeItWork()
{
    
    std::cout << "DEBUT COMPONENT" << std::endl;
    return ;
}