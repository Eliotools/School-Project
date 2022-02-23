/*
** EPITECH PROJECT, 2019
** convert_binaire convert_hexa
** File description:
** convert in bin or hexa
*/

#include <stdlib.h>
#include "my.h"

char *int_binaire(int value)
{
    char *list = malloc(100);
    int tmp = 0;
    int i = 0;
    do {
        tmp = value % 2;
        list[i] = tmp + 48;
        value = (value) / 2;
        tmp = 0;
        i++;
    } while (value != 0);
    list = my_revstr(list);
    return (list);
}

char *int_hexa_maj(int value)
{
    char *list = malloc(100);
    char hex[17] = "0123456789ABCDEF";
    int i = 0;
    int tmp = 0;
    do {
        tmp = value % 16;
        list[i] = hex[tmp];
        value = (value) / 16;
        tmp = 0;
        i++;
    } while (value != 0);
    list = my_revstr(list);
    return (list);
}

char *int_hexa_min(int value)
{
    char *list = malloc(100);
    char hex[17] = "0123456789ABCDEF";
    int i = 0;
    int tmp = 0;
    do {
        tmp = value % 16;
        list[i] = hex[tmp];
        value = (value) / 16;
        tmp = 0;
        i++;
    } while (value != 0);
    list = my_revstr(list);
    return (list);
}