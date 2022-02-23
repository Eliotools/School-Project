/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/

#include <stdlib.h>
#include "include/phoenix.h"

char *duplicate_string(char const *src)
{
    char *str = malloc(sizeof(char) * len(src));

    for (int i = 0; src[i] != '\0';str[i] = src[i], i++);
    return (str);
}