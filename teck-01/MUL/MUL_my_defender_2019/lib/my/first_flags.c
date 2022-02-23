/*
** EPITECH PROJECT, 2019
** first_flags
** File description:
** printf
*/

#include <unistd.h>
#include "include/my.h"
#include <stdlib.h>
#include <stdarg.h>

int first_flags(char *str, int counter, va_list list)
{
    if (str[counter] == '%' && str[counter + 1] == 's') {
        my_putstr(va_arg(list, char *));
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == 'c') {
        my_putchar(va_arg(list, int));
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == 'd') {
        my_put_nbr(va_arg(list, int));
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == 'i') {
        my_put_nbr(va_arg(list, int));
        counter += 2;
    }
    return (counter);
}
