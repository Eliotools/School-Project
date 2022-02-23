/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** task05 Day06
*/

#include <stdio.h>

int size_of_string(char const *to_find)
{
    int nb = 0;

    while (to_find[nb] != '\0') {
        nb++;
    }
    return (nb);
}

char *my_strstr(char *str, char const *to_find)
{
    int size = size_of_string(to_find);
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[j])
            j++;
        if (str[i + 1] != to_find[j] && j != size)
            j = 0;
        if (j == size)
            return (&str[i - (j -1)]);
        i++;
    }
}
