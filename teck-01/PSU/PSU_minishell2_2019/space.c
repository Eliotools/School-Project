/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include "my.h"

char *cut(char *to_save)
{
    char *buffer = verif_m(sizeof(char) * 9999);
    char *new = verif_m(sizeof(char) * 9999);

    buffer = space_z();
    to_save = deleted(to_save, '\n');
    while (my_strcmp(buffer, to_save, '\n') != 0)
    {
        new = my_strcat(new, buffer);
        new = my_strcat(new, " ");
        buffer = space_z();
    }
    return (new);
}

char *space_z(void)
{
    size_t size = 999;
    char *buffer = verif_m(sizeof(char) *size);
    int i = 0;

    while (i < 2) {
        my_printf("heredoc>");
        i = getline(&buffer, &size, stdin);
    }
    buffer = deleted(buffer, '\n');
    return (buffer);
}

char *double_right(char *str, used_t *used)
{
    char *new = verif_m(len(str));
    char *to_save = verif_m(len(str));
    int j = 0;
    int k = 0;
 for (int i = 0; str[i]; i++)
    {
        if (str[i] == '<') {
            k = 1;
            i += 2;
        }
        if (k == 0)
            new[i] = str[i];
        else {
            to_save[j] = str[i];
            j++;
        }
    } str = cut(to_save);
    piping(str, used);
    return (new);
}

char *del(char *str, char c)
{
    int j = 0;
    int things = 0;
    char *new = verif_m(len(str));
for (int i = 0; str[i] != '\0'; i++, j++)
    {
        if (str[i] == ' ' && str[i+1] == c)
            i++;
        if (str[i] == ' ' && str[i-1] == c)
            i++;
        new[j] = str[i];
    }
    return (new);
}

char *double_left(char *str)
{
    char *new = verif_m(len(str));
    char *to_read = verif_m(len(str));
    int k = 0;
    int j = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '>') {
            k = 1;
            i += 2;
        }
        if (k == 0)
            new[i] = str[i];
        else {
            to_read[j] = str[i];
            j++;
        }
    }
    k = open(to_read, O_WRONLY | O_CREAT, 0644 | O_APPEND);
    dup2(k, 1);
    return (new);
}