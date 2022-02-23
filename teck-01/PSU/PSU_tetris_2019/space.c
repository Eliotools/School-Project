/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "include/my.h"

variables_t init_struc(variables_t variables)
{
    variables.drop = 0;
    variables.get = 0;
    variables.stop = 0;
    variables.x = 6;
    variables.y = 2;
    variables.size = 0;

    return (variables);
}

char **watch_line(char **other)
{
    int k = 1;
    int j = 0;
    for (; other; j++) {
        for (k = 1;other[j] || other[j][k] == '*';k++);
        if (k == 16)
            other = (modif_all(other, j));
    }
    return (other);
}

char **modif_all(char **map, int j)
{
    for (int i = 1; i != 13; i++)
        map[j][i] = ' ';
    while (j >= 1)
    {
        map[j-1] = map[j];
        j--;
    }
    return (map);
}

forme_t *turn(forme_t *forme)
{
    char **new = malloc(sizeof(char *) * forme->col);
    int clone = forme->col;
    for (int j = 0; j != forme->col; j++)
        new[j] = malloc(sizeof(char) * forme->line);
    for (int j = 0; j != forme->col+1; j++) {
        for (int k = 0; k != forme->line-1; k++) {
            new[k][j] = forme->forme[j][k];
        }
    }
    forme->col = forme->line;
    forme->line = clone;
    forme->forme = new;
    forme->compte = 1;
    return (forme);
}