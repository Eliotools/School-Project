/*
** EPITECH PROJECT, 2019
** hexa
** File description:
** printf
*/

#include <unistd.h>
#include "include/my.h"

int my_put_nbr_bin(int nb)
{
    if (nb > 2)
        my_put_nbr_bin(nb / 2);
    my_putchar ((nb % 2) + '0');
    return (0);
}
