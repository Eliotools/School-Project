/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07M-eliot.martin
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    this->_stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{    
}
WarpSystem::Core::Core(QuantumReactor *Q_r)
{
    this->_coreReactor = Q_r;
}

WarpSystem::Core::~Core()
{

}

bool WarpSystem::QuantumReactor::isStable()
{
    return(this->_stability);
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return(_coreReactor);
}
void WarpSystem::QuantumReactor::setStability(bool stab)
{
        this->_stability = stab;

}