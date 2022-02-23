/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD15-eliot.martin
** File description:
** ex04
*/
#include <string>
#include "ex04.hpp"

template<> bool Tester<int>::equal(const int& a, const int& b) 
{
    return a == b;
}
template<> bool Tester<float>::equal(const float& a, const float& b) 
{
    return a == b;
}
template<> bool Tester<double>::equal(const double& a, const double& b) 
{
    return a == b;
}
template<> bool Tester<std::string>::equal(const std::string& a, const std::string& b) 
{
    return a.compare(b) == 0;
}

template <> bool equal(int const& a, int const &b) 
{
    return a == b;
}
template <> bool equal(float const& a, float const &b) 
{
    return a == b;
}
template <> bool equal(double const& a, double const &b) 
{
    return a == b;
}
template <> bool equal(std::string const& a, std::string const &b) 
{
    return (a.compare(b) == 0);
}