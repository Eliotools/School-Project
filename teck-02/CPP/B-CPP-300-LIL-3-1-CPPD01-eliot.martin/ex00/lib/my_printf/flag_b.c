/*
** EPITECH PROJECT, 2019
** flag
** File description:
** flag
*/

#include "../../include/printf.h"
#include "../../include/phoenix.h"
#include <stdarg.h>

void percent_(void)
{
    my_putchar('%');
}

void percent_u(va_list list)
{
    show_number(va_arg(list, int));
}

void percent_o(va_list list)
{
    show_number(converteur(va_arg(list, int), 8));
}

void percent_x(va_list list)
{
    show_string_array(va_arg(list, char **));
}