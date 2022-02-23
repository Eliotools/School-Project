/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD07M-eliot.martin
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        public:
        QuantumReactor() ;
        ~QuantumReactor();

        bool isStable();
        void setStability(bool stability);
        protected:
        private:
        bool _stability;
    };
    class Core {
        public:
            Core(QuantumReactor * Q_r);
            ~Core();
            QuantumReactor *checkReactor();

            QuantumReactor *_coreReactor;
    };
};

#endif /* !WARPSYSTEM_HPP_ */
