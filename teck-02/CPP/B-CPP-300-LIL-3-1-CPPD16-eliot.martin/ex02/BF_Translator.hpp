/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** BF_Translator
*/

#ifndef BF_TRANSLATOR_HPP_
#define BF_TRANSLATOR_HPP_
#include <string>
#include <map>
class BF_Translator {
    public:
        BF_Translator();
        ~BF_Translator();
        int translate(const std::string &in, const std::string &out);

    protected:
    private:
        std::map<char, char *> map;
        std::pair<char, char *> pair;
};

#endif /* !BF_TRANSLATOR_HPP_ */
