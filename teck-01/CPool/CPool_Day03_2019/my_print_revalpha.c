/*
** EPITECH PROJECT, 2019
** my_print_revalpha.c
** File description:  
** displays the lowercase alphabet in descending order
*/

#include <unistd.h>

int  my_print_alpha(void)
{
    char print;

    for (print = 122; print > 96; print -= 1)
    {
        my_putchar(print);

    }
}
