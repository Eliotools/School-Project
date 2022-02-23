/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** file
*/

#include "lib.h"

char *remove_quote(char *str)
{
    char *new = malloc(strlen(str) + 1);

    if (str[0] == '\"' && str[strlen(str) - 1] == '\"'){
        for (int i = 1; str[i] != '\"'; i++)
            new[i - 1] = str[i];
    } else
        return (str);
    return (new);
}

char *remove_chars(char *s, char c)
{
    int writer = 0;
    int reader = 0;
    char *tmp = malloc(strlen(s) + 1);

    while (s[reader]) {
        if (s[reader] != c) {
            tmp[writer++] = s[reader];
        }
        reader++;
    }
    tmp[writer] = 0;
    return (tmp);
}

char *open_file(char *filename)
{
    char *cwd = malloc(2048);
    char *all = malloc(2048 + strlen(filename));

    if ((cwd = getcwd(NULL, 0)) != NULL) {
        sprintf(all, "%s/%s", cwd, filename);
        return all;
    } else {
        perror("getcwd() error");
        return NULL;
    }
}

char *get_nth(char *str, int i)
{
    str = strtok(str, "\"");
    for (int k = 1; k != i; k++)
        str = strtok(NULL, "\"");

    return (str);
}