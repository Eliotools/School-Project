/*
** EPITECH PROJECT, 2019
** my_compte_factorial_it
** File description:
** facto
*/
#include <unistd.h>

int my_compute_factorial_rec (int nb)
{
    int counter;
    if (nb >= 13)
        return (0);
    if (nb == 1)
        return (1);
    if (nb == 0 )
        return (1);
    if (nb < 0 )
        return (0);
    counter = nb *  my_compute_factorial_rec(nb - 1);
    return (counter);
}
