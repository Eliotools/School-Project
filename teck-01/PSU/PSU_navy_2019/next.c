/*
** EPITECH PROJECT, 2020
** navy
** File description:
** Moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "include/printf.h"
#include "include/phoenix.h"
#include "my.h"

int finding_twice(char *pos)
{
    int i = 0;
    for (; pos[i] >= 91 || pos[i] <= 64; i++);
    return (i);
}

void maper(char *geo, char **map, char k)
{
    char clone = k;
    int j = to_number(geo);
    int abs = j % 10 + 1;
    int ord = ((j - abs) / 10) * 2 + 2;
    if (map[abs][ord] != '.' || (map[abs][ord] >= '2' && map[abs][ord] <= '5')){
        k = 'X';
        if (clone == 'o')
            my_printf("hit\n\n");
    } else if (k == 'o')
        my_printf("missed\n\n");
    map[abs][ord] = k;
}

char *filler(char *pos, char *str, int i, int j)
{
    str = malloc(sizeof(char) * 2);
    str[0] = pos[i] - 16;
    str[1] = pos[j];
    return (str);
}

void space_x(char *first, char *second, char **map, char k)
{
    char clone = k - 2;
    while (clone > '0'){
        first[1] += 1;
        maper(first, map, k);
        clone--;
    }
}

void space_y(char *first, char *second, char **map, char k)
{
    char clone = k - 2;
    while (clone > '0'){
        first[0] += 1;
        maper(first, map, k);
        clone--;
    }
}