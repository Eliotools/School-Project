/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** Event
*/

#include "Event.hpp"

Event::Event()
{
}

Event::Event(unsigned int nb, std::string str) : _time(nb), _event(str)
{
}

Event::~Event()
{
}

Event::Event(const Event &other)
{
    _time = other._time;
    _event = other._event;
}

Event &Event::operator=(const Event &rhs)
{
    _time = rhs._time;
    _event = rhs._event;
    return (*this);
}

unsigned int Event::getTime() const
{
    return _time;
}

const std::string &Event::getEvent() const
{
    return _event;
}

void Event::setTime(unsigned int time)
{
    _time = time;
}

void Event::setEvent(std::string &event)
{
    _event = event;
}