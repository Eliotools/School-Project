/*
** EPITECH PROJECT, 2020
** dante/generator
** File description:
** Moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/phoenix.h"

char **make_my_map(char **map, int x, int y)
{
    for (int i = 0; i != y; i++) {
        if (i%2 == 1) {
            map[i] = malloc(sizeof(char) * x+2);
            map[i][x] = '\n';
            map[i][x+1] = '\0';
            for (int j = 0; j != x; j++)
            map[i][j] = '*';
        } if (i%2 == 0) {
            map[i] = malloc(sizeof(char) * x+2);
            map[i][x] = '\n';
            map[i][x+1] = '\0';
            for (int j = 0; j != x; j++)
            map[i][j] = 'X';
        }
        map[y-1][x] = '\0';

}

int main(int ac, char **av)
{
    if (ac != 2 || ac != 3)
        return (84);
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    char **map = malloc(sizeof(char *) * y+1);

    map = make_my_map(map, x, y);
    }
    /*if (ac == 4 && strcmp(av[3],"bite") == 0)
        map = perfect_drill(map, co);
    else
        map = unperfect_drill(map, co);*/
   for (int i = 0; i != y; i++)
        printf(map[i]);
    free(map);
    return (0);
}