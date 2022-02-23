/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** task06 Day05
*/

int test(int nb)
{
    if (nb % 2 == 0)
        return (0);
    if (nb % 3 == 0)
        return (0);
    if (nb % 5 == 0)
        return (0);
    if (nb % 7 == 0)
        return (0);
}

int my_is_prime(int nb)
{
    int i = nb;
    if (nb < 0)
        return (0);
    if (nb == 1)
        return (0);
    if (nb == 2)
        return (1);
    if (!test(nb))
        return (0);
    while (i > 2) {
        if (nb % i != 0) {
            i--;
            return (0);
        }
        if (nb % i == 0) {
            i--;
            return (1);
        }
    }
}
