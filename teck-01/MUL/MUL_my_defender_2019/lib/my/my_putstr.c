/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_putstr.c
*/

#include <unistd.h>

void my_pchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_pchar(str[i]);
    return (0);
}
