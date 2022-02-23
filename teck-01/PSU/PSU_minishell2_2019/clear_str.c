/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include "my.h"

char *delet_space(char *str, char c)
{
    char *new = verif_m(len(str));
    int j = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    for (int i = 0; str[i]; i++, j++)
    {
        while (str[i] == ' ' && (str[i+1] == ' ' || str[i+1] == c))
            i++;
        new[j] = str[i];
    }
    free (str);
    new[j] = '\0';
    return (delet_again(new, c));
}

char **clean(char *str)
{
    char **final = str_to_word_array(str, ';');
    return (final);
}

int find_space(char *str, int i)
{
    while ((str[i] == ' ' || str[i] == '\t') && str[i])
        i++;

    return (i);
}

char *delet_again(char *str, char c)
{
    char *new = verif_m(len(str));
    int j = 0;
    int i = 0;
    if (str[0] == ' ')
        i++;
    for (; str[i] != '\0'; i++, j++)
    {
        if (str[i] == ' ' && str[i+1] == c) {
            new[j] = c;
            i += 2;
            j++;
            } if (str[i] == c && str[i+1] == ' ') {
                new[j] = str[i];
                i += 2;
                j++;
            }
            new[j] = str[i];
    }
    new[j] = '\0';
    return (new);
}