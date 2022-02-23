/*
** EPITECH PROJECT, 2019
** flag
** File description:
** flag
*/

#include "../../include/printf.h"
#include "../../include/phoenix.h"
#include "printf.h"
#include <stdarg.h>

int my_new_putstr(char const *str, int base);

void pourcent_id(va_list list)
{
    show_number(va_arg(list, int));
}

void pourcent_s(va_list list)
{
    show_string(va_arg(list, char *));
}

void pourcent_c(va_list list)
{
    my_putchar(va_arg(list, int));
}

void pourcent_b(va_list list)
{
    show_string(itob(va_arg(list, int)));
}

void pourcent_big_s(va_list list)
{
    my_new_putstr(va_arg(list, char *), 8);
}