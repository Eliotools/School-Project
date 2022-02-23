/*
** EPITECH PROJECT, 2019
** string_to_double_tab.c
** File description:
** string to double array
*/

#include <stdlib.h>

int my_linelen(char const *str)
{
    int i = 0;
    int j = 0;
    int longest = 0;

    while (str[i] != '\0') {
        if (j > longest)
            longest = j;
        i++;
        j++;
        if (str[i] == '\n')
            j = 0;
    }
    return (longest);
}

int get_nbr_lines(char const *str)
{
    int n = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            n++;
    return (n);
}

char **string_to_tab(const char *str)
{
    char **tab;
    int i = 0;
    int j = 0;
    int k = 0;
    tab = malloc(sizeof(char *) * (get_nbr_lines(str) + 1000));
    while (str[i] != '\0') {
        tab[k] = malloc(sizeof(char) * (my_linelen(str) + 2000));
        j = 0;
        while (str[i] != '\n') {
            if (str[i] == '\0')
                break;
            tab[k][j] = str[i];
            i = i + 1;
            j = j + 1;
        }
        tab[k][j] = '\0';
        k = k + 1;
        i = i + 1;
    } tab[k] = NULL;
    return (tab);
}
