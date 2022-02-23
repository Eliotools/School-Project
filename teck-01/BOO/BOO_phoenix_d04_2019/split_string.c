/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/

#include "include/phoenix.h"
#include <stdlib.h>

int find_space(char const *str)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] > 'Z' || str[i] < 'A') && (str[i] > 'z' || str[i] < 'a') &&
        (str[i] < '0' || str[i] > '9')) {
            j++;
        }
    j++;
    return (j);
}

int len_space(char const *str, int j)
{
    int i = 0;
    while (((str[j] <= 'Z' && str[j] >= 'A') || (str[j] <= 'z' &&
str[j] >= 'a') || (str[i] >= '0' && str[i] <= '9')) && j < len(str)) {
            i++;
            j++;
    }
    return (i);
}

char *fill(int k, char const *str, char **autre, int j)
{
    int i = 0;
    while (((str[j] <= 'Z' && str[j] >= 'A') || (str[j] <= 'z' &&
str[j] >= 'a') || (str[i] >= '0' && str[i] <= '9')) && j < len(str))
    {
        autre[k][i] = str[j];
        j++;
        i++;
    }
    return (autre[k]);
}

int again(char const *str, int j)
{
    int i = 0;
    while (((str[j] > 'Z' || str[j] < 'A') && (str[j] > 'z' ||
str[j] < 'a') && (str[i] < '0' || str[i] > '9')) && j < len(str)) {
        j++;
        i++;
    }
    return (i);
}

char **split_string(char const *str)
{
    int k = 0;
    int j = 0;
    int clone = 0;
    char **autre = malloc(sizeof(char *) * find_space(str)+1);

    for (int j = 0; j < len(str); j++)
    {
        j += len_space(str, j);
        autre[k] = malloc(sizeof(char)* j);
        autre[k] = fill(k, str, autre, clone);
        j += again(str, j);
        clone = j;
        k++;
    }
    autre[k] = NULL;
    return (autre);
}
