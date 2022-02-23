/*
** EPITECH PROJECT, 2019
** hexa
** File description:
** printf
*/

#include <unistd.h>
#include "include/my.h"

int my_put_nbr_octa(int nb)
{
    if (nb < 0) {
        my_putchar ('-');
        my_putchar ((nb / 8) * -1);
        my_putchar (((nb % 8) * -1) + '0');
    }
    else {
        if (nb > 8)
            my_put_nbr_octa(nb / 8);
        my_putchar ((nb % 8) + '0');
    }
    return (0);
}
