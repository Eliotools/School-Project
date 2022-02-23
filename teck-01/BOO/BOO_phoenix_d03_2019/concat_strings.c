/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/

#include "include/phoenix.h"
#include <stdio.h>


char *concat_strings (char *dest, char const *src)
{
    int l = len(dest);
    int i = len(src);
    int k = 0;
    int j = 0;

    for (; j < i; j++) {
        dest[l + j] = src[j];
    }
    dest[l + j] = '\0';
    return (dest);
}