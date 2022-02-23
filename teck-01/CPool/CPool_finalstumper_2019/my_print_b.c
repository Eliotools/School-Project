/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/

#include "my.h"
#include "rush3.h"

void my_print_b(char *buff)
{
    my_putstr("[rush1-3] ");
    print_size(buff);
    my_putstr(" || ");
    my_putstr("[rush1-4] ");
    print_size(buff);
    my_putstr(" || ");
    my_putstr("[rush1-5] ");
    print_size(buff);
    my_putchar('\n');
}