/*
** EPITECH PROJECT, 2019
** my_putstr_error
** File description:
** Print str
*/

#include "my.h"

int   my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar_error(str[i]);
        i++;
    }
}
