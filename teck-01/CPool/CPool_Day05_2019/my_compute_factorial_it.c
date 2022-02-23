/*
** EPITECH PROJECT, 2019
** my_compte_factorial_it
** File description:
** facto
*/
#include <unistd.h>

int my_compute_factorial_it (int nb)
{
    int i = (nb - 1);

    if (nb == 1)
        return (1);
    if (nb == 0 )
        return (1);
    if (nb < 0 )
        return (0);
    while (i != 0)
    {
        nb = nb * i;
        i--;
    }
    return (nb);
}

