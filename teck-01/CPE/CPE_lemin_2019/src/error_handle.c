/*
** EPITECH PROJECT, 2020
** error_handle.c
** File description:
** error handle
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"
#include "function.h"

int is_it_number(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            break;
        if (str[i] == '-')
            break;
        if (str[i] < '0' || str[i] > '9')
            return (84);
        i++;
    }
    return (0);
}

int error_handling(char *buffer)
{
    char **split = string_to_tab(buffer);
    int check_endstart = 0;

    if (is_it_number(split[0]) == 84)
        return (84);
    for (int m = 0; split[m] != NULL; m++) {
        if (my_strcmp(split[m], "##start") == 0)
            check_endstart++;
        if (my_strcmp(split[m], "##end") == 0)
            check_endstart++;
        if (my_strcmp(split[m], "##start") != 0 &&
        is_it_number(split[m]) == 84 && split[m][0] != '#')
            return (84);
        if (my_strcmp(split[m], "##end") != 0 &&
        is_it_number(split[m]) == 84 && split[m][0] != '#')
            return (84);
    }
    if (check_endstart != 2)
        return (84);
    return (0);
}
