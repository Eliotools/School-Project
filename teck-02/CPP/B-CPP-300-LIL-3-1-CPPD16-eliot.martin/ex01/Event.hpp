/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_
#include <string>

class Event {
    public:
        Event();
        Event(unsigned int nb, std::string str);
        ~Event();
        Event(const Event &other);
        Event &operator=(const Event &rhs);
        unsigned int getTime() const;
        const std::string &getEvent() const;
        void setTime(unsigned int time);
        void setEvent(std::string &event);
        void dumpEventAt(unsigned int time) const;
    protected:
        unsigned int _time;
        std::string _event;
};

#endif /* !EVENT_HPP_ */
