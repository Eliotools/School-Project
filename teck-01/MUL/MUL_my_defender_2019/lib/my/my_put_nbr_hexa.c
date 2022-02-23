/*
** EPITECH PROJECT, 2019
** hexa
** File description:
** printf
*/

#include <unistd.h>
#include "include/my.h"

int my_put_nbr_hexa(int nb)
{
    if (nb < 0) {
        my_putchar ('-');
        my_putchar ((nb / 16) * -1);
        my_putchar (((nb % 16) * -1) + '0');
    }
    else {
        if (nb > 16)
            my_put_nbr_hexa(nb / 16);
        my_putchar ((nb % 16) + '0');
    }
    return (0);
}
