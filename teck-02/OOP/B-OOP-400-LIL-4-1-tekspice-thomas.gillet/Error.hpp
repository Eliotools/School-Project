/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** BaseError
*/

#ifndef BASEERROR_HPP_
#define BASEERROR_HPP_
#include <exception>
#include <string>

class BaseError : public std::exception{
    public:
        BaseError(std::string const &message);
        ~BaseError();

        std::string const &get(std::string const &message) const;
        const char *what() const noexcept;
    private:
        std::string _message;
};

class ParseError : public BaseError{
    public:
        ParseError(const std::string &message);
};

class ComponentError : public BaseError{
    public:
        ComponentError(std::string const &message);
};

class CircuitError : public BaseError{
    public:
        CircuitError(std::string const &message);
};

#endif /* !BASEERROR_HPP_ */
