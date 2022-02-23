/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** task04 Day05
*/

int my_compute_power_rec(int nb, int p)
{
    int res = nb;
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    res = nb * my_compute_power_rec(nb, p - 1);
    return (res);
}
