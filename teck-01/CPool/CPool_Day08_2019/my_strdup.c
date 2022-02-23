/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** dup
*/
#include <stdlib.h>
#include <stdio.h>

char my_strdup(char const *src)
{
    int j = 0;
    int i = 0;
    char *str;

    for (i = 0; src[i] != '\0'; ++i);
    str = malloc(sizeof(char) * (i + 1));
    while (j != i)
    {
        str[j] = src[j];
        j++;
    }
    str[j] = '\0';
    return (str);
}
