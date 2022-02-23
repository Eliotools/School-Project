/*
** EPITECH PROJECT, 2020
** basics.C
** File description:
** basic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_put_nbr(int nb)
{
    int mod;
    if (nb < 0)
    {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = -147483648;
        }
        nb = -nb;
    }
    if (nb < 10) {
        my_putchar(nb + 48);
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        mod = nb % 10;
        my_putchar(mod + 48);
    }
    return (0);
}

int my_strcmp(char *s1, char *s2)
{
    int i;
    i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            if (s1[i] > s2[i])
                return (1);
            if (s1[i] < s2[i])
                return (-1);
        }
        i++;
    }
    return (0);
}

int number(char *str)
{
    int int_str = 0;
    int i = 0;

    if (str[0] == '-')
        i = 1;
    for (; str[i] != '\0'; i++) {
        int_str = int_str * 10 + str[i] - 48;
    }
    if (str[0] == '-')
        return (-int_str);
    else
        return (int_str);
}
