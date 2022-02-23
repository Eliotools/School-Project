/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "my.h"

char *add(char *src, char c)
{
    int i = 0;
    char *new = malloc(sizeof(char) * len(src)+1);

    for (; src[i]; i++)
        new[i] = src[i];
    new[len(src)] = c;
    return (new);
}

char *delet(char *src, char c)
{
    int j = 0;
    if (len(src) -1 < 0)
        return (NULL);
    char *new = malloc(sizeof(char) * len(src)-1);
    for (int i = 0; src[i]; i++, j++) {
        if (src[i] != c)
            new[j] = src[i];
        else
            j--;
    }
    return (new);
}

int *init_way(char *X, char c)
{
    int *way = malloc(sizeof(int) * len(X));
    for (int i = 0; i != len(X)+1; i++)
        way[i] = 220;
    way[c-48] = 0;
    return (way);
}

int **init_distance(char *X, char s)
{
    int **distance = malloc(sizeof(int *) * len(X));

    for (int i = 0; distance[i]; i++) {
        distance[i] = malloc(sizeof(int) * len(X));
        for (int j = 0; distance[i][j]; j++)
            distance[i][j] = 220;
    }
    distance[s-48][s-48] = 0;
    return (distance);
}

int is_in(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
        {
            return (0);
        }
    }
    return (1);
}

