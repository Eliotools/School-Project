/*
** EPITECH PROJECT, 2024
** day05
** File description:
** Created by Leo Fabre
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0 || nb == 1) {
        return (1);
    } else if (nb > 0)
        return (nb * my_compute_factorial_rec(nb - 1));
    return (0);
}