/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD15-eliot.martin
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_


#endif /* !EX02_HPP_ */

template<typename T>
T min(T a, T b)
{
    std::cout << "template min" << std::endl;
    if (b < a)
        return b;
    return a;
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (b < a)
        return b;
    return a;
}

template<typename T>
T templateMin(T *array, int size)
{
    if (size < 2)
        return (array[0]);
    int nb = 1;
    T mini = min<T>(array[0],array[nb]);
    nb++;
    while (nb < size) {
        mini = min(mini, array[nb]);
        nb++;
    }
    return mini;
}

int nonTemplateMin(int *array, int size)
{
    if (size < 2)
        return (array[0]);
    if (size == 0)
        return (0);
    int nb = 1;
    int mini = min(array[0],array[nb]);
    nb++;
    while (nb < size) {
        mini = min(nb, array[nb]);
        nb++;
    }
    return mini;
}