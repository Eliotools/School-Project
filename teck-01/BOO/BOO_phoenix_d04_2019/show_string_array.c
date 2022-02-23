/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/
#include "include/phoenix.h"

int show_string_array(char *const *array)
{
    int i = 0;
    while (array[i] != 0)
    {
        show_string(array[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
