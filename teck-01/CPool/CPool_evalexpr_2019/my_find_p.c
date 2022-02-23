/*
** EPITECH PROJECT, 2019
** find_p
** File description:
** eval_expr
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

char *find_p(char *str)
{
    int i = 0;
    int j = 0;
    char *futur = malloc(sizeof(char) *(my_strlen(str)));
    while (str[i] != ')' || str[i] < my_strlen(str)) {
        i++;
    }
    str[i] = '~';
    j = i;
    while (str[j] != '(' || str[j] != str[0]) {
        j--;
    }
    str[j] = '~';
    j++;
    futur = my_copy(futur, str, j, i);
    return (futur);
}

char *my_copy(char *dest, char const *src, int j, int i)
{
    int k = 0;
    while (src[j] != src[i]) {
        dest[k] = src[j];
        j++;
        k++;
    }
    dest[k] = '\0';
    return (dest);
}
