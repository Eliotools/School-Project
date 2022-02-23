/*
** EPITECH PROJECT, 2019
** my_compute__square_root
** File description:
** task05 Day05
*/

int verif(int nb)
{
    for (int i; i != nb - 1; i++)
    {
        if (i * i == nb)
            return (i);
    }
    return (0);
}

int my_compute_square_root(int nb)
{
    int res;
    if (nb < 1)
        return (0);
    if (verif(nb))
    {
        res = nb/verif(nb);
        return (res);
    }
}
