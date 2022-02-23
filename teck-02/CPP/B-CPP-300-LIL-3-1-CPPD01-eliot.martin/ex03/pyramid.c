/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/
#include <stdio.h>
#include <math.h>

int next(int size, const int **map)
{
    int result = map[0][0];
    int x = 0;
    int i = 1;

    while (i < size)
    {
        if (rand() % 101 > 50)
            result += map[i][x];
        else
            result += map[i][x++];
        i++;
    }
    return (result);
}

int pyramid_path(int size, const int **map)
{
    int shortest = 696969;
    int result = 0;
    for (int i = 0; i <= 2000; i++){
        result = next(size, map);
        if (result < shortest)
        shortest = result;
    }
return (shortest);
}
