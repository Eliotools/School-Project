/*
** EPITECH PROJECT, 2024
** day05
** File description:
** Created by Leo Fabre
*/

int my_compute_square_root(int nb)
{
    int res = 0;
    if (nb < 0 || nb == 0)
        return 0;
    for (; (res * res) != nb; ++res)
        if (res > nb)
            return 0;
    return res;
}