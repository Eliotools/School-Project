/*
** EPITECH PROJECT, 2019
** esab
** File description:
** esab
*/

#include "include/my.h"
#include <stdio.h>
#include <unistd.h>

char *convert_rev(char *mod, char *to_mod, int i, char *classique)
{

    int j = 0;

    while (to_mod[j] != '\0')
    {
        if (classique[i] == to_mod[j])
            to_mod[j] = mod[i];
        j++;
    }
    return (to_mod);
}

char *base_rev(char *mod, char *to_mod)
{
    char *classique = "0123456789\0";
    int i = 0;

    while (classique[i] != '\0')
    {
        convert_rev(mod, to_mod, i, classique);
        i++;
    }
    return (to_mod);
}
