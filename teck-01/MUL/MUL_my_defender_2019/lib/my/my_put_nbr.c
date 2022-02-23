/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar ('-');
        my_putchar ((nb / 10) * -1);
        my_putchar (((nb % 10) * -1) + '0');
    }
    else {
        if (nb >= 10)
            my_put_nbr(nb / 10);
        my_putchar ((nb % 10) + '0');
    }
    return (0);
}
