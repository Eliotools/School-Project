/*
** EPITECH PROJECT, 2019
** flag
** File description:
** flag
*/

#include "include/my.h"
#include "my.h"
#include <stdarg.h>

void pourcent_ (void)
{
    my_putchar('%');
}

void pourcent_u (va_list list)
{
    my_put_unsigned_nbr(va_arg(list, int));
}

void pourcent_o (va_list list)
{
    my_put_nbr(converteur(va_arg(list, int), 8));
}

void pourcent_X (va_list list)
{
    my_putstr("À faire");
}

void pourcent_x (va_list list)
{
    my_putstr("À faire");
}