/*
** EPITECH PROJECT, 2019
** print_error
** File description:
** bistro
*/

#include "include/my.h"

void print_error(char *av)
{
    my_putstr("Usage: ");
    my_putstr(av);
    my_putstr(" base ops\"()+_*/%\" exp_len\n");
}
