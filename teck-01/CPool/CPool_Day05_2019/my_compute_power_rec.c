/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** power
*/
#include <unistd.h>
#include <stdio.h>

int my_compute_power_rec (int nb, int p)
{
    int usless = nb;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (p > 13)
        return (0);
    nb = nb * my_compute_factorial_rec(usless, p -= 1);
    return (nb);
}
