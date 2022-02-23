/*
** EPITECH PROJECT, 2019
** Projet Bistrot
** File description:
** base.c
*/

#include "include/my.h"

char *convert_base(char *mod, char *to_mod, int i, char *classique)
{
    int j = 0;

    while (to_mod[j] != '\0') {
        if (mod[i] == to_mod[j])
            to_mod[j] = classique[i];
        j++;
    }
    return (to_mod);
}

char *base_char(char *mod, char *to_mod)
{
    char *classique = "0123456789";
    int i = 0;

    while (mod[i] != '\0') {
        convert_base(mod, to_mod, i, classique);
        i++;
    }
    return (to_mod);
}

char *base_calc(char *mod, char *to_mod)
{
    char *classique = "()+-*/%";
    int i = 0;

    while (mod[i] != '\0') {
        convert_base(mod, to_mod, i, classique);
        i++;
    }
    return (to_mod);
}
