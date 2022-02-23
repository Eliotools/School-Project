/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-tekspice-thomas.gillet [WSL: Ubuntu]
** File description:
** Error
*/

#include "Error.hpp"

BaseError::BaseError(std::string const &message) : _message(message)
{
}

BaseError::~BaseError()
{
}

ParseError::ParseError(const std::string &message) : BaseError(message)
{
}

ComponentError::ComponentError(const std::string &message) : BaseError(message)
{
}

CircuitError::CircuitError(const std::string &message) : BaseError(message)
{
}

const char *BaseError::what() const noexcept
{
    return _message.c_str();
}
