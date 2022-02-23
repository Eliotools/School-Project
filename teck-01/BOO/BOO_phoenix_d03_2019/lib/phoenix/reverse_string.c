/*
** EPITECH PROJECT, 2019
** Phenix
** File description:
** Moi
*/
#include <stdio.h>

int len(char const *str);

char *reverse_string(char *str)
{
    int l = len(str)-1;
    int i = 0;
    char clone;

    while (i < l)
    {
        clone = str[i];
        str[i] = str[l];
        str[l] = clone;
        l--;
        i++;
    }
    return (str);
}