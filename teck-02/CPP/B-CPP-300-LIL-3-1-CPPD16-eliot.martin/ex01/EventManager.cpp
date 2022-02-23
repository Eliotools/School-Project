/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** EventManager
*/

#include "EventManager.hpp"
#include <iostream>
bool sortbytime(Event &first, const Event &second);

EventManager::EventManager() : _time(0)
{
}

EventManager::~EventManager()
{
}

EventManager::EventManager(const EventManager &other)
{
    _l1 = other._l1;
    _time = other._time;
}

EventManager &EventManager::operator=(const EventManager &rhs)
{
    _l1 = rhs._l1;
    _time = rhs._time;
    return (*this);
}

void EventManager::addEvent(const Event &e)
{
    if (e.getTime() <= _time)
        return;
    _l1.push_back(e);
    _l1.sort(sortbytime);
}

void EventManager::removeEventsAt(unsigned int time)
{
    for (auto it = _l1.begin(); it != _l1.end(); it++) {
        if (it->getTime() == time) {
            _l1.erase(it);
            it = _l1.begin();
        }
    }
}

void EventManager::dumpEvents() const
{
    for (auto it = _l1.begin(); it != _l1.end(); it++)
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (auto it = _l1.begin(); it != _l1.end(); it++)
    {
        if (it->getTime() == time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
    }
}

void EventManager::addTime(unsigned int time)
{
    unsigned int old = _time;
    _time += time;
        while (old != _time+1) {
            dumpEventAt2(old);
            removeEventsAt(old);
            old++;
        }
}

void EventManager::dumpEventAt2(unsigned int time) const
{
    for (auto it = _l1.begin(); it != _l1.end(); it++)
    {
        if (it->getTime() == time)
            std::cout << it->getEvent() << std::endl;
    }
}

bool sortbytime(Event &first, const Event &second)
{
    return (first.getTime() <= second.getTime());
}

void  EventManager::addEventList(const std::list <Event > events)
{
    for (auto it = events.begin(); it != events.end(); it++)
        addEvent(*it);
}