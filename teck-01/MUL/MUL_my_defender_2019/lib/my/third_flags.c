/*
** EPITECH PROJECT, 2019
** third
** File description:
** printf
*/

#include <unistd.h>
#include "include/my.h"
#include <stdarg.h>

int third_flags(char *str, int counter, va_list list)
{
    if (str[counter] == '%' && str[counter + 1] == 'x') {
        my_put_nbr_hexa(va_arg(list, int));
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == 'X') {
        my_put_nbr_hexa(va_arg(list, int));
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == 'S') {
        my_put_nbr_octa(va_arg(list, int));
        counter += 2;
    }
    if (str[counter] == '%' && str[counter + 1] == 'p') {
        my_put_nbr_octa(va_arg(list, int));
        counter += 2;
    }
    return (counter);
}
    
