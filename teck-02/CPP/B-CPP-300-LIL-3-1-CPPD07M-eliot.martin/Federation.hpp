/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07M-eliot.martin
** File description:
** Federation
*/

#include "WarpSystem.hpp"

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

namespace Federation {
     class Ship {
            public:
                Ship(int length, int width, std:: string name);
                ~Ship();
                void setupCore(WarpSystem::Core *Core);
                void checkCore();

            protected:
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp; 
                WarpSystem::Core *Core;

        };
    namespace Starfleet {
        class Ensign {
            public:
                Ensign(std::string name);
                ~Ensign();
            protected:
            private:
                std::string _name;
        };
        class Captain {
            public:
                Captain(std::string name);
                ~Captain();

                std::string getName();
                int getAge();
                void setAge(int age);
            protected:
            private:
            std:: string _name;
            int _age; 
        };
        class Ship {
            public:
                Ship(int length, int width, std:: string name, short maxWarp);
                ~Ship();
                void setupCore(WarpSystem::Core *Core);
                void checkCore();
                void  promote(Captain *captain);

            protected:
            private:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                Starfleet::Captain *Captain; 
                WarpSystem::Core *Core;

        };
    };
};




#endif /* !FEDERATION_HPP_ */
