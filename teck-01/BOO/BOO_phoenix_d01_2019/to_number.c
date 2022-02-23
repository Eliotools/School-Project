/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** Leo Fabre
*/
#include <stdlib.h>

void show_number (int a);

int to_number(char const *str)
{
    int res = 0;
    int clone = 0;
    int sign = 1;
    int i = 0;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9')); i++) {
        clone = res;
        res *= 10;
        res += str[i] - '0';
        if (res < clone)
        {
            show_number(0);
            return(84);
        }
    }
    return (res * sign);
}