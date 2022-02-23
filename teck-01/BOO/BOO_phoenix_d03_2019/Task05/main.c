/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/

#include "../include/phoenix.h"
#include <stdio.h>

char *transpho_str (char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = 127;
        i++;
    }
    return (str);
}

void space_x (int argc, char **argv, int k)
{
    int compte = 127;
    int save = 0;
    int i = 0;
    for (; i < argc; i++) {
        if (argv[i][0] < compte) {
            save = i;
            compte = argv[i][0];
        }
    }
    show_string(argv[save]);
    my_putchar('\n');
    argv[save] = transpho_str(argv[save]);
    k++;
    if (k != argc)
        space_x(argc, argv, k);

}

int main (int argc, char **argv)
{
    int k = 0;
    space_x(argc, argv, k);
    return (0);
}