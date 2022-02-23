/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD17-eliot.martin
** File description:
** MyAlgorithms
*/

#ifndef FIND_HPP
#define FIND_HPP
#include <algorithm>

template<typename T>
typename T::iterator do_find(T& contain, int n)
{
  return std::find(contain.begin(), contain.end(), n);
}


#endif
