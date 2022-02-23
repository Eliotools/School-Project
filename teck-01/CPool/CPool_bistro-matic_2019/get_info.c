/*
** EPITECH PROJECT, 2019
** get_info
** File description:
** bistro
*/

#include <stdio.h>
#include <unistd.h>
#include "include/my.h"
#include "bistromatic.h"
#include <stdlib.h>

int get_info(char *av)
{
    int i = 0;

    i = info(av);
    if (i == 84) {
        write(2, "syntax error", 13);
        exit(84);
    }
    return (i);
}
