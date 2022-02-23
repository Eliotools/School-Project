/*
** EPITECH PROJECT, 2024
** day04
** File description:
** Created by Leo Fabre
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i]; i++) {
        my_putchar(str[i]);
    }
    return 0;
}