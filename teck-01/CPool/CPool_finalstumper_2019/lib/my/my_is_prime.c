/*
** EPITECH PROJECT, 2024
** day05
** File description:
** Created by Leo Fabre
*/

int my_compute_square_root(int nb);

int my_is_prime(int nb)
{
    int divider = 5;

    if (nb == 1 || nb == 2 || nb == 3 || nb == 5)
        return 1;
    if ((nb % 2 == 0) || (nb % 3 == 0))
        return 0;
    while (divider <= my_compute_square_root(nb)) {
        if (nb % divider == 0) {
            return 0;
        } else
            divider += 2;
    }
    return 1;
}
