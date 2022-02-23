/*
** EPITECH PROJECT, 2019
** flag
** File description:
** flag
*/

#include "../../include/printf.h"
#include "../../include/phoenix.h"
#include <stdarg.h>

void pourcent_(void)
{
    my_putchar('%');
}

void pourcent_u(va_list list)
{
    show_number(va_arg(list, int));
}

void pourcent_o(va_list list)
{
    show_number(converteur(va_arg(list, int), 8));
}

void pourcent_X(va_list list)
{
    show_string("À faire");
}

void pourcent_x(va_list list)
{
    show_string("À faire");
}