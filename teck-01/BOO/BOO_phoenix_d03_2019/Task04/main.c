/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/

#include "../include/phoenix.h"
#include <stdio.h>

int main (int argc, char **argv)
{
    int i = 0;
    while (i != argc)
    {
        show_string(argv[i]);
        my_putchar('\n');
        i++;
    }
    return(0);
}
