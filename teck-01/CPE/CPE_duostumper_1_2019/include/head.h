/*
** EPITECH PROJECT, 2020
** header
** File description:
** header head
*/

#ifndef HEAD_H_
#define HEAD_H_

#include <stdlib.h>
#include <unistd.h>

typedef struct args {
    int c;
    int n;
    int q;
    int v;
    char **tab;
    int nb_files;
    int size;
} args_t;

void my_putstr(char *str);

int my_strlen(char *str);

int my_strcmp(char *str1, char *str2);

#endif /* !HEAD_H */
