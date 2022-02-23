/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** Moi
*/
#include <stdlib.h>

void show_number (int a);

int to_number(char const *str)
{
    int diz = 0;
    int clone = 0;
    int neg = 1;
    int i = 0;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            neg *= -1;
    for (; ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9')); i++) {
        clone = diz;
        diz *= 10;
        diz += str[i] - '0';
        if (diz < clone)
        {
            show_number(0);
            return (84);
        }
    }
    return (diz * neg);
}