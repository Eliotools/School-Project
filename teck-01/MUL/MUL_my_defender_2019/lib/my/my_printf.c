/*
** EPITECH PROJECT, 2019
** printf
** File description:
** printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

//unsigned int for unsigned

int my_printf(char *str, ...)
{
    va_list list;
    int counter = 0;

    va_start(list, str);
    while (str[counter] != '\0') {
        counter = first_flags(str, counter, list);
        counter = second_flags(str, counter, list);
        counter = third_flags(str, counter, list);
        my_putchar(str[counter]);
        counter++;
    }
    return (counter);
}
