/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** eval_expr
*/

#include "include/my.h"
#include <stdlib.h>

int eval_expr(char *av)
{
    char *new = 0;
    int i = 0;
    int params = 0;
    char signe = '0';

    while (av[i] != '\0') {
        if (av[i] == '(')
            params++;
        i++;
    }
    i = 0;
    if (params != 0)
        new = find_p(av);
    else new = (av);
    while (new[i + 1] != '\0' && signe == '0') {
        signe = negative(new, i);
        i++;
    }
    i = parsing(new, signe);
    return (i);
}
