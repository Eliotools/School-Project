/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr_u(int nb)
{
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar ((nb % 10) + '0');
    return (0);
}
