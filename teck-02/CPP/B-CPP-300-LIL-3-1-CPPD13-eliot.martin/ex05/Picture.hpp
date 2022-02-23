/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD13-eliot.martin
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Picture {
    public:
        Picture();
        Picture(const Picture &pic);
        Picture(const std::string &file);
        ~Picture();
        std::string _data;
        bool getPictureFromFile(const std::string &file);
        Picture &operator=(const Picture &pic);  

    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
