/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD06-eliot.martin
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

class KoalaDoctor {
    public:
        KoalaDoctor(std::string new_name);
        ~KoalaDoctor();
        
        void timeCheck(void);
        void diagnose(SickKoala *patient); 
        std::string getName(void);
    protected:
    private:
        std::string name;
        bool work;

};

#endif /* !KOALADOCTOR_HPP_ */
