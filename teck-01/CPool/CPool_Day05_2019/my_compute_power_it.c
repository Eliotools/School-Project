/*
** EPITECH PROJECT, 2019
** my_compte_power_it
** File description:
** power
*/


#include <unistd.h>

int my_compute_power_it(int nb, int p)
{
    int    usless = nb;
    p--;
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (p > 12)
        return (0);
    while (p != 0)
    {
        nb = (nb * usless);
        p--;
    }
    return (nb);
}

