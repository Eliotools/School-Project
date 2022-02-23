/*
** EPITECH PROJECT, 2019
** convert_octal
** File description:
** convert dec in octal
*/

#include <stdlib.h>
#include "my.h"

int int_octal(int value)
{
    char *list = malloc(7);
    list[3] = '\\';
    list[2] = '0';
    list[1] = '0';
    list[0] = '0';
    int tmp = 0;
    int i = 0;
    do {
        tmp = value % 8;
        list[i] = tmp + 48;
        value = (value) / 8;
        tmp = 0;
        i++;
    } while (value != 0);
    list = my_revstr(list);
    my_putstr(list);
    return (0);
}

int int_simple_octal(int value)
{
    char *list = malloc(100);
    int tmp = 0;
    int i = 0;
    do {
        tmp = value % 8;
        list[i] = tmp + 48;
        value = (value) / 8;
        tmp = 0;
        i++;
    } while (value != 0);
    list = my_revstr(list);
    my_putstr(list);
    return (0);
}
