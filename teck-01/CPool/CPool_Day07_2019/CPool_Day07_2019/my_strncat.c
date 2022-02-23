/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** ncat
*/
#include <stdio.h>
#include <stddef.h>
#include <string.h>

char *my_strncat(char *dest, const char *src, int nb )
{
    int i = 0;
    char rev[100];
    int j = 0;

    for (i = 0 ; src[i] != '\0' ; i++)
        rev[i] = src[i];
    while (nb != 0)
    {
        rev[i] = dest[j];
        i++;
        j++;
        nb--;
    }
    rev[i] = '\0';
    return (rev);
}

