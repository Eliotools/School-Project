/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_strdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;
    int j = 0;
    while (src[i])
        i++;
    dest = malloc(sizeof(char) * i + 1);
    while (j < i) {
        dest[j] = src[j];
        j++;
    }
    dest[j] = '\0';
    return (dest);
}