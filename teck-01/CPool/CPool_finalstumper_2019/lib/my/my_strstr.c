/*
** EPITECH PROJECT, 2024
** day06
** File description:
** Created by Leo Fabre
*/
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    for (; str[i] != '\0'; ++i) {
        for (; to_find[j] == str[i]; ++j)
            if (to_find[j + 1] == '\0') {
                for (;str[i] == ' '; ++i);
                return &str[i - j];
            }
    }
    return NULL;
}