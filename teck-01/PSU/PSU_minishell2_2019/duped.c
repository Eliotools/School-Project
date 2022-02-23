/*
** EPITECH PROJECT, 2020
** mini
** File description:
** MOi
*/

#include "my.h"

int check_sup(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] == '<' && buffer[i+1] == '<')
            return (3);
        if (buffer[i] == '>' && buffer[i+1] == '>')
            return (2);
        if (buffer[i] == '<')
            return (1);
        if (buffer[i] == '>')
            return (0);
    }
    return (5);
}

char *check_redirect(char *str, used_t *used)
{
    int i = check_sup(str);

    if (i == 0)
        return (left(del(str, '>'), used));
    if (i == 1)
        return (right(del(str, '<'), used));
    if (i == 2)
        return (double_left(del(str, '>')));
    if (i == 3)
        return (double_right(del(str, '<'), used));
    return (str);
}

char *right(char *str, used_t *used)
{
    char *new = malloc(sizeof(str));
    char *to_read = malloc(sizeof(str));
    int k = 0;
    int j = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '<') {
            k = 1;
            i += 1;
        }
        if (k == 0)
            new[i] = str[i];
        else {
            to_read[j] = str[i];
            j++;
        }
    } used->to_close = dup2((k = open(to_read, O_RDONLY)), 0);
    close (k);
    return (new);
}

char *left(char *str, used_t *used)
{
    char *new = verif_m(len(str));
    char *to_read = verif_m(len(str));
    int k = 0;
    int j = 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '>') {
            k = 1;
            i += 1;
        }
        if (k == 0)
            new[i] = str[i];
        else {
            to_read[j] = str[i];
            j++;
        }
    } k = open(to_read, O_WRONLY | O_CREAT, 0644);
    used->to_close = dup2(k, 1);
    return (new);
}

void set_std(used_t *used)
{
    close (used->to_close);
    dup2(used->clone_in, 0);
    dup2(used->clone_out, 1);
}