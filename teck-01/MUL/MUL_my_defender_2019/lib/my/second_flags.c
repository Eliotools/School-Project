/*
** EPITECH PROJECT, 2019
** second
** File description:
** printf
*/

#include <stdio.h>
#include <unistd.h>
#include "include/my.h"
#include <stdarg.h>

int second_flags(char *str, int counter, va_list list)
{
    if (str[counter] == '%' && str[counter + 1] == 'u') {
        my_put_nbr_u(va_arg(list, unsigned int));
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == 'o') {
        my_put_nbr_octa(va_arg(list, int));
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == '%'
        && str[counter + 2] != '%') {
        my_putchar('%');
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == 'b') {
        my_put_nbr_bin(va_arg(list, int));
        counter += 2;
    }
    return (counter);
}
