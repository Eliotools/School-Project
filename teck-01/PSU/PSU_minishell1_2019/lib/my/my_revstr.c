/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverse str
*/
#include <string.h>

char    *my_revstr(char *str)
{
    char tp;
    int i = 0;
    int j = 0;

    while (str[j] != '\0')
        j++;

    j = j - 1;

    while (i < j)
    {
        tp = str[i];
        str[i] = str[j];
        str[j] = tp;
        i++;
        j--;
    }

    return (str);
}
