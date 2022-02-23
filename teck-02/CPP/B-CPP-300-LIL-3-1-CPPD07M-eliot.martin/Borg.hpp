/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07M-eliot.martin
** File description:
** Borg
*/
#include "WarpSystem.hpp"

#ifndef BORG_HPP_
#define BORG_HPP_

namespace Borg {
    class Ship {
        public:
            Ship();
            ~Ship();
            void setupCore(WarpSystem::Core *Core);
            void checkCore();
        protected:
        private:
            int _side;
            short _maxWarp; 
            WarpSystem::Core *Core;

        };
};
#endif /* !BORG_HPP_ */
