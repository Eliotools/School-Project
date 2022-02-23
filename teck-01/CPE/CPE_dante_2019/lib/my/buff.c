/*
** EPITECH PROJECT, 2019
** printf
** File description:
** printf
*/
#include <stdlib.h>
#include <stdio.h>

int len_buff ()
{
    int offset = 0;
    char *buffer = stdout;
    int len = 0;

    while ((len = read(1, buffer + offset, 200 - offset))> 0){
        offset += len;
    }
    free (buffer);
    printf("i = %i", offset);
}
