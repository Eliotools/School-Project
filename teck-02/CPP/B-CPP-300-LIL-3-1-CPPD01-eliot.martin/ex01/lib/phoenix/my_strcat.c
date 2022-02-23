/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by Leo Fabre
*/

#include <stdio.h>
#include <stdlib.h>
#include "phoenix.h"

char *my_strcat(char *src, char const *dest)
{
    char *new = malloc(sizeof(char) * len(dest) + len(src) + 1);
    int i = 0;

    while (src[i]) {
    new[i] = src[i];
    i++;
    }
    for (int j = 0; dest[j]; j++, i++)
        new[i] = dest[j];
    new[i] = '\0';
    return (new);
}