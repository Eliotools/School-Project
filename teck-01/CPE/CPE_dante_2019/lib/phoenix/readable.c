/*
** EPITECH PROJECT, 2020
** readable
** File description:
** Moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *readable(char *path)
{
    int i = 0;
    char *buffer = malloc(sizeof(char) * 9999);

    i = open(path, O_RDONLY);
    if (i == -1){
        return "NULL";
    } else {
        read(i, buffer, 9999);
    }
    return buffer;
}