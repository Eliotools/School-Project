/*
** EPITECH PROJECT, 2020
** duo
** File description:
** Moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int is_readable(char **array, int nb)
{
    int k = 0;

    for (int i = 0; i != nb - 1; i++) {
        if ((open(array[i], O_RDONLY)) != -1) {
            k++;
        }
    }
        return (k);
}
