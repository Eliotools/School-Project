/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** revers
*/
#include <stdio.h>

int my_strlen(char * str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *my_revstr(char *str)
{
    int   i;
    int   j;
    char usless;

    i = 0;
    j = my_strlen(str) - 1;
    while (i < j)
    {
        usless = str[i];
        str[i] = str[j];
        str[j] = usless;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}

