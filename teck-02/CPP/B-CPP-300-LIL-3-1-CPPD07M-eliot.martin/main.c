/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07M-eliot.martin
** File description:
** Federation
*/

#include <iostream>
#include "WarpSystem.hpp"
#include "Federation.hpp"
#include "Borg.hpp"

int main()
{
Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
Federation::Starfleet::Captain James("James T. Kirk");
Federation::Starfleet::Ensign Ensign("Pavel Chekov");
WarpSystem::QuantumReactor QR ;
WarpSystem::QuantumReactor QR2 ;
WarpSystem::Core core (& QR ) ;
WarpSystem::Core core2 (& QR2 ) ;
UssKreog.setupCore (& core ) ;
UssKreog.checkCore () ;
UssKreog.promote (& James ) ;
Borg::Ship Cube ;
Cube.setupCore (& core2 ) ;
Cube.checkCore () ;
return 0;
}