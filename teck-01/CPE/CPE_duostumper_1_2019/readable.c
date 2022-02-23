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
#include "head.h"

int my_getnbr(char const *str);

void my_putstr(char *str);

void my_putchar(char c);

char *readable(char *path)
{
    int i = 0;
    char *buffer = malloc(sizeof(char) * 99999);

    i = open(path, O_RDONLY);
    if (buffer == NULL)
        return (NULL);
    if (i == -1){
        return "NULL";
    } else {
        i = read(i, buffer, 99999);
    }
    return buffer;
}

int next_b(char *path, int nb_char)
{
    int i = 0;
    char *buffer = (readable(path));

    if (buffer == NULL)
        return (NULL);
    if (my_strcmp(buffer, "NULL") == 0) {
        my_putstr("head: cannot open '");
        my_putstr(path);
        my_putstr("' for reading: No such file or dircetory");
        return (1);
    }
    while (i != nb_char) {
        my_putchar(buffer[i]);
        if (i == my_strlen(buffer)) {
            free(buffer);
            return (0);
        }
        i++;
    }
    return (0);
}

int next_l(char *path, int nb_line)
{
    int i = 0;
    int j = 0;
    char *buffer = (readable(path));

    if (buffer == NULL)
        return (NULL);
    if (my_strcmp(buffer, "NULL") == 0) {
        my_putstr("head: cannot open '");
        my_putstr(path);
        my_putstr("' for reading: No such file or directory");
        return (1);
    }
    while (i != nb_line) {
        my_putchar(buffer[j]);
        if (buffer[j] == '\n')
            i++;
        if (j == my_strlen(buffer)) {
            free(buffer);
            return (0);
        }
        j++;
    }
    return (0);
}

int is_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (1);
    return (0);
}

int main_loop(args_t *args, int ac, char **av)
{
    int i = is_readable(av, ac);

    if (i > 1)
        args->v = 1;
    for (int i = 1; i != ac; i++) {
        if (av[i][0] != '-' && is_number(av[i]) != 0) {
            if (args->v == 1) {
                my_putstr("==> ");
                my_putstr(av[i]);
                my_putstr(" <==\n");
            } if (args->c == 1)
                next_b(av[i], args->size);
            if (args->n == 1)
                next_l(av[i], args->size);
            if (args->n == 0 && args->c == 0)
                next_l(av[i], 10);
            my_putstr("\n");
        }
    }
}
