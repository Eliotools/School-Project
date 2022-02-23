/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD15-eliot.martin
** File description:
** ex03
*/

#ifndef EX03_HPP_
#define EX03_HPP_

template<typename T>
void foreach(const T *array, void(&fonc)(const T &elem), int size)
{
    for (int i = 0; i < size; i++)
    {
        fonc(array[i]);
    }
}

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

#endif /* !EX03_HPP_ */
