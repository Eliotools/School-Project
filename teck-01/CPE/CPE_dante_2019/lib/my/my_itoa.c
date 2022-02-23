/*
** EPITECH PROJECT, 2019
** itoa
** File description:
** bistomatic
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *convert(int past, int size)
{
    char *futur = malloc(sizeof(char) * (size));

    if (past < 0) {
        size -= 1;
        past = past*-1;
    }
    while (size != 0) {
        futur[size - 1] = past % 10 + 48;
        past = past / 10;
        size--;
    }
    return (futur);
}

char *my_itoa(int past)
{
    int size = 0;
    int clone = past;
    char *futur = 0;

    while (clone != 0) {
        clone = clone / 10;
        size++;
    }
    futur = convert(past, size);
    if (past < 0)
        futur[0] = '-';
    return (futur);
}