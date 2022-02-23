/*
** EPITECH PROJECT, 2020
** chartochar
** File description:
** Moi
*/
#include "phoenix.h"
#include <stdlib.h>

char *chartochar(char **array)
{
    int compte = 0;
    char *new;
    int z = 0;

    for (int i = 0; array[i]; i++)
        compte += len(array[i])+1;
    new = malloc(sizeof(char) * compte);
    for (int y = 0; array[y]; y++)
    {
        for (int x = 0; array[y][x]; x++)
        {
            new[z] = array[y][x];
            z++;
        }
        new[z] = '\n';
        z++;
    }
    return (new);
}