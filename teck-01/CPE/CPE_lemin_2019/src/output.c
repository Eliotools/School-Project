/*
** EPITECH PROJECT, 2020
** output.c
** File description:
** output
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"
#include "function.h"

char *purify(char *contaminated)
{
    char *pure = malloc(sizeof(char) * BUFSIZ);
    int i;

    if (my_strcmp(contaminated, "##start") == 0)
        return (contaminated);
    if (my_strcmp(contaminated, "##end") == 0)
        return (contaminated);
    for (i = 0; contaminated[i] != '#'; i++) {
        pure[i] = contaminated[i];
        if (contaminated[i] == '\0')
            break;
    }
    if (pure[i - 1] == ' ') {
        while (pure[i - 1] == ' ') {
            pure[i - 1] = '\0';
            i--;
        }
    }
    return (pure);
}

void display(char **split, int tun)
{
    my_putstr("#number_of_ants\n");
    my_putstr(purify(split[0]));
    my_putstr("\n#rooms\n");
    for (int m = 1; split[m] != NULL; m++) {
        if (split[m][0] == '#' && split[m][1] != '#')
            m++;
        if (split[m][1] == '-' && tun == 0) {
            write(1, "#tunnels\n", 9);
            tun = 1;
        }
        my_putstr(purify(split[m]));
        my_putchar('\n');
    }
    my_putstr("#moves\n");
}

int output(char *buffer)
{
    char **split;
    int tun = 0;

    split = string_to_tab(buffer);
    display(split, tun);
    return (0);
}