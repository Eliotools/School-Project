/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include "my.h"

char *take_after(char *env, char c)
{
    int i = 0;
    int j = 0;
    char *new = verif_m(sizeof(char) * (len(env)));
    while (env[i] != c)
        i++;
    i++;
    for (; env[i]; j++, i++)
        new[j] = env[i];
    new[j] = '\0';
    return (new);
}

void my_print_env(char **env)
{
    for (int i = 0; env[i]; i++)
        if (my_strcmp(env[i], "z", '\0') == 1)
            my_printf("%s\n", env[i]);
}

char *verif_m(int size)
{
    char *str = malloc(size+1);

    if (str == NULL)
        exit;
    str[size] = '\0';
    return (str);
}

char **verif_md(int size)
{
    char **str = malloc(size+1);

    if (str == NULL)
        exit;
    return (str);
}