/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** strcpy
*/
#include <stdio.h>

char *my_strncpy (char *dest, char const *src, int n)
{
    int i = 0;
    int j;

    while (i != n)
    {
        dest[i] = src[i];
        i++;
    }
    for (j = 0; dest[j] != '\0'; ++j);
    if (dest[i+1] != '\0')
        dest[j] = '\0';
    return (dest);
}





