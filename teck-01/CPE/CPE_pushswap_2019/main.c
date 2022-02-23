/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Moi
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void recurcive(int *array, int *sizes, int smaller, int i);

void find_smaller(int *array, int size)
{
    int smaller = 0;
    int i = 0;
    int sizes[2];
    sizes[0] = size;
    sizes[1] = size;
    recurcive(array, sizes, smaller, i);
}

int *change_array(int *array, int smaller, int size)
{
    int *new = malloc(sizeof(int) * (size));
    int j = 0;
    int i = 0;
    for (; i < size; i++)
    {
        if (i == smaller)
            i++;
        new[j] = array[i];
        j++;
    }
    return (new);
}

int *swich(int *array, int smaller, int size)
{
    while (smaller != 0) {
        int k = array[0];
        for (int i = 1; i != size; i++)
            array [i-1] = array[i];
        array[size-1] = k;
        smaller--;
        my_putstr("sa ");
    }
    return (array);
}

void recurcive(int *array, int *sizes, int smaller, int i)
{
    int j = 0;
    while (j != sizes[0]) {
        if (smaller == sizes[0]) {
            smaller--;
        }
        if (array[j] >= array[smaller]) {
            smaller = j;
        }
        j++;
    }
    i++;
    array = change_array(array, smaller, sizes[0]);
    if (sizes[0] != sizes[1])
        my_putstr("pb ");
    if (smaller != 0)
        array = swich(array, smaller, sizes[0]-1);
    if (i != sizes[1]) {
        sizes[0] = sizes[0]-1;
        recurcive(array, sizes, smaller, i);
    }
}

int main(int argc, char **argv)
{
    if (argc == 1)
        exit(84);
    int i = 0;
    int j = 0;
    int new;
    int size = argc-1;
    int *array = malloc(sizeof(int) * (size));


    for (i = 1; i != argc; i++, j++) {
        new = my_getnbr(argv[i]);
        array[j] = new;
    }
    find_smaller(array, size);
    my_putstr("pb\n");
    return (0);
}
