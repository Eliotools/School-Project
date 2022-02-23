/*
** EPITECH PROJECT, 2020
** match
** File description:
** Moi
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/phoenix.h"
#include "include/printf.h"

char *take_str(char *str, int col);

char **take_array(int line)
{
    int j = 1 + (line - 1) * 2 + 2;
    char **array = malloc(sizeof(char *) * line+2);

    for (int i = 0; i != line+2; i++)
        array[i] = malloc(sizeof(char) * j);
    array[line+3] = "0";
    for (int i = 0; i != j; i++)
        array[0][i] = '*';
    for (int i = 0; i != j; i++)
        array[line+1][i] = '*';
    for (int i = 1; i != line+1; i++)
    {
        array[i] = take_str(array[i], j);
    }
    return array;
}

int *take_number(char **array, int line)
{
    int i = 1;
    int k = 0;
    int *number = malloc(sizeof(int) * line);
    while (i != line + 1) {
        for (int j = 0; j != len(array[i]); j++)
            if (array[i][j] == '|') {
                k++;
            }
        number[i] = k;
        k = 0;
        i++;
    }
    return (number);
}

int take_all_number(int *number, int line)
{
    int i = 0;
    for (int j = 0; j != line+1; j++)
        i += number[j];
    return i;
}