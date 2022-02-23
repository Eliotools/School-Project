/*
** EPITECH PROJECT, 2019
** calculatron
** File description:
** les calculs
*/

#include "include/my.h"
#include <stdlib.h>

int calculatron(int one, int two, char signe)
{
    int resulty = 0;

    if (signe == '+')
        resulty = (add(one, two));
    if (signe == '-')
        resulty = (negate(one, two));
    if (signe == '%')
        resulty = (modulo(one, two));
    if (signe == '/')
        resulty = (divi(one, two));
    if (signe == '*')
        resulty = (times(one, two));
    return (resulty);
}
