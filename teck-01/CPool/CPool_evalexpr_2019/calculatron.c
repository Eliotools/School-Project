/*
** EPITECH PROJECT, 2019
** calculatron
** File description:
** les calculs
*/

#include "include/my.h"
#include <stdlib.h>

int calculatron(int uno, int dos, char signe)
{
    int resulty = 0;

    if (signe == '+')
        resulty = (plus(uno, dos));
    if (signe == '-')
        resulty = (moinss(uno, dos));
    if (signe == '%')
        resulty = (modulo(uno, dos));
    if (signe == '/')
        resulty = (divi(uno, dos));
    if (signe == '*')
        resulty = (foie(uno, dos));
    return (resulty);
}
