/*
** EPITECH PROJECT, 2019
** Phenix
** File description:
** Moi
*/

#include <stdio.h>
#include "phoenix.h"

char *reverse_string(char *str)
{
    int L = len(str)-1;
    int i = 0;
    char clone;

    while (i < L)
    {
        clone = str[i];
        str[i] = str[L];
        str[L] = clone;
        L--;
        i++;
    }
    return (str);
}