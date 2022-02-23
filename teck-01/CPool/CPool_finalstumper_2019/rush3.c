/*
** EPITECH PROJECT, 2024
** my_project
** File description:
** Created by Leo Fabre
*/

#include "my.h"
#include "rush3.h"

int my_firstline_len(char *str)
{
    int i = 0;

    for(; str[i] != '\n'; i++);
    return (i);
}

int my_count_lines(char *buff)
{
    int newlines = 0;

    for(int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n')
            newlines++;
    return (newlines);
}

char last_char (char *str, int l)
{
    int i = 0;

    if (l == 0){
        for (;str[i] != '\0'; i++);
        return (str[i - 2]);
    }
    for (; str[i] != '\n'; i++);
    return (str[i - 1]);
}

void print_size(char *buff)
{
    int len = my_firstline_len(buff);
    int nb_lines = my_count_lines(buff);

    my_put_nbr(len);
    my_putchar(' ');
    my_put_nbr(nb_lines);
}

int rush3(char *buff)
{
    char last_fs = last_char(buff, 1);
    char last_ls = last_char(buff, 0);

    if (last_ls == 'B'){
        my_print_b(buff);
        return (0);
    } else if (last_fs == 'o')
        my_putstr("[rush1-1] ");
    else if (last_fs == '\\' || last_fs == '*')
        my_putstr("[rush1-2] ");
    else if (last_fs == 'A')
        my_putstr("[rush1-3] ");
    else if (last_fs == 'C' && last_ls == 'C')
        my_putstr("[rush1-4] ");
    else if (last_fs == 'C' && last_ls == 'A')
        my_putstr("[rush1-5] ");
    print_size(buff);
    my_putchar('\n');
    return (0);
}
