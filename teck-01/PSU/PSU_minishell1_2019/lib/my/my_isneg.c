/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** Print P or N, P for positive (or null ) N for negative
*/

#include "my.h"

int my_isneg(int n)
{
    char print;

    if (n<0) {
        print = 78;
    } else {
        print = 80;
    }

    my_putchar(print);
}
