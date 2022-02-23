/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description: 
** displays the lowercase alphabet in ascending order 
*/

#include <unistd.h>

int  my_print_alpha(void)
{
    char print;

    for (print = 97; print < 123; print += 1)
    {
    my_putchar(print);
    }
}
    

    
