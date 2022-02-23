/*
** EPITECH PROJECT, 2019
** parsing
** File description:
** eval_expr
*/

#include "include/my.h"
#include <stdlib.h>

int parsing(char *av, char signe)
{
    int i = 0;
    int j = 0;
    int marqun = 0;
    int marqdeux = 0;
    char *saveuno = malloc(sizeof(char) *(my_strlen(av)));
    char *savedos = malloc(sizeof(char) *(my_strlen(av)));

    if (av[i] == '-') {
        av[i] = '_';
        marqun = 1;
        i++;
    }
    while ((av[i] >= '0' && av[i] <= '9' ) && i <= my_strlen(av) - 1) {
            saveuno[j] = av[i];
            i++;
            j++;
    }
    j = 0;
    if (av[i+1] == '-') {
        av[i+1] = '_';
        marqdeux = 1;
        i++;
    }
    i++;
    while ((av[i] >= '0' && av[i] <= '9') || i <= my_strlen(av)) {
            savedos[j] = av[i];
            i++;
            j++;
    }
    saveuno = my_realloc(saveuno, i);
    savedos = my_realloc(savedos, j);
    i = (my_strtol(saveuno, marqun));
    j = (my_strtol(savedos, marqdeux));
    return (calculatron (i, j, signe));
}

char *my_realloc(char *save, int size)
{
    int i = 0;
    char *final = malloc(sizeof(char) * (size));

    while (save[i] != save[size]) {
        final[i] = save[i];
        i++;
    }
    free(save);
    return (final);
}
