#include "include/my.h"
#include <stdlib.h>

int parsing(char *av, char signe)
{
    int    i = 0;
    int    j = 0;
    int marqun = 0;
    int marqdeux = 0;
    char *saveI = malloc(sizeof(char) *(my_strlen(av)));
    char *saveII = malloc(sizeof(char) *(my_strlen(av)));

    if (av[i] == '-') {
        av[i] = '_';
        my_putchar('Y');
        marqun = 1;
        i++;
    }
    while ((av[i] >= '0' && av[i] <= '9' ) && i <= my_strlen(av) - 1) {
            saveI[j] = av[i];
            i++;
            j++;
    }   
    j = 0;
    if (av[i+1] == '-') {
        av[i+1] = '_';
        my_putchar('N');
        marqdeux = 1;
        i++;
    }
    i++;
    while ((av[i] >= '0' && av[i] <= '9') || i <= my_strlen(av)) {
            saveII[j] = av[i];
            i++;
            j++;
    }
    saveI = my_realloc(saveI, i);
    saveII = my_realloc(saveII, j);
    i = (my_strtol(saveI, marqun));
    j = (my_strtol(saveII, marqdeux));
    return(calculatron (i, j, signe));
}

int my_realloc(char *save, int size)
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