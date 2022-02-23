/*
** EPITECH PROJECT, 2019
** phoenix
** File description:
** Moi
*/

#include <stddef.h>
#include <stdio.h>

int len(char const *str);

int find_str(char *str, char const *to_find, int stock, int j)
{
    while (str[stock] == to_find[j]) {
        if (to_find[j] == to_find[len(to_find)-1])
            return (1);
        stock++;
        j++;
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int stock;
    int k = 0;

    while (str[i] != '\0') {
        if (str[i] == to_find[j]) {
            stock = i;
            k = find_str(str, to_find, stock, j);
        }
        if (k == 1)
            return (&str[i]);
        i++;
    }
    return (0);
}