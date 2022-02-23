/*
** EPITECH PROJECT, 2019
** my_print_digits.c
** File description:
** displays the digits,on a single line, in ascending order
*/

#include <unistd.h>

int  my_print_alpha(void)
{
    char print;

    for (print = 48; print < 58; print += 1)
    {
        my_putchar(print);

    }
}
