/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** EventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_
#include <list>
#include "Event.hpp"

class EventManager {
    public:
        EventManager();
        ~EventManager();
        EventManager(EventManager  const &other);
        EventManager &operator =( EventManager  const &rhs);
        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;
        void dumpEventAt2(unsigned int time) const;
        void addTime(unsigned int time);
        void addEventList(const std::list <Event> events);
    private :
        std::list <Event> _l1;
        unsigned int _time;
};

#endif /* !EVENTMANAGER_HPP_ */
