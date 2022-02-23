/*
** EPITECH PROJECT, 2020
** tristant
** File description:
** Moi
*/

#include <stdlib.h>
#include <stdio.h>
#include "include/phoenix.h"

int main (int ac, char **av)
{
    int i = 0;
    int j = 0;
    char *final;
    
    if (len(av[1]) >= (len(av[2])))
        final = malloc(sizeof(char) * len(av[1]));
    if (len(av[1]) < (len(av[2])))
	final = malloc(sizeof(char) * len(av[2]));
    for(; i != (len(av[1])/2); i++)
        final[i] = av[1][i];
    j = len(av[2])/2;
    for(; j != len(av[2]); j++, i++) {
        final[i] = av[2][j];
    }
    printf("%s + %s = %s\n", av[1], av[2], final);
}
