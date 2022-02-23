/*
** EPITECH PROJECT, 2020
** asking
** File description:
** Moi
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "phoenix.h"

int asking_int(void)
{
    size_t size = 999;
    char *buffer = malloc(sizeof(char) *size);
    int line = 0;

    getline(&buffer, &size, stdin);
    line = to_number(buffer);
    return (line);
}

char *asking_char(void)
{
    size_t size = 999;
    char *buffer = malloc(sizeof(char) *size);
    buffer = NULL;
    int i = 0;
    int access = 0;

    while (access != 2)
    {
        access = 0;
        show_string("$>");
        i = getline(&buffer, &size, stdin);
        if (i >= 2)
            access += 1;
        if (access == 1)
            access = check_buff(buffer);
    }
    return (buffer);
}

int check_buff(char *buffer)
{
    int i = 0;
    while ((buffer[i]))
    {
        if (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\n')
            return (2);
        i++;
    }
    return (0);
}