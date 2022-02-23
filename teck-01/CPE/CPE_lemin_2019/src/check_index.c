/*
** EPITECH PROJECT, 2020
** check_index.c
** File description:
** check index
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"
#include "function.h"

char check_index(char val, char **name)
{
    int i = 0;
    for (i = 0; name[i] != NULL; i++){
        if (val == name[i][0])
            return (i + 48);
    }
    return (i + 48);
}

char *check_index_2(char *val, char **name)
{
    char val_0 = val[0];
    char val_1 = val[1];

    for (int i = 0; name[i] != NULL; i++){
        if (val_0 == name[i][0])
            val[0] = i + 48;
        if (val_1 == name[i][0])
            val[1] = i + 48;
    }
    return (val);
}
