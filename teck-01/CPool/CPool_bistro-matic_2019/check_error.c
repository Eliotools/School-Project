/*
** EPITECH PROJECT, 2019
** check_error
** File description:
** bistro
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"

int check_error(char *av)
{
    int i = 0;
    int k = 0;

    while (av[i] != '\0') {
        if (av[i] == '/' && av[i + 1] == '0')
            k = 84;
        if (av[i] == '%' && av[i + 1] == '0')
            k = 84;
        i++;
    }
    return (k);
}
