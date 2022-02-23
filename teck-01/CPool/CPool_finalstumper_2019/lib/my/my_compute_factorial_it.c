/*
** EPITECH PROJECT, 2024
** day05
** File description:
** Created by Leo Fabre
*/

int my_compute_factorial_it(int nb)
{
    int res = 1;

    if (nb == 0)
        return 1;
    if (nb < 0 || nb >= 13)
        return 0;
    if (res > 0){
        for (int c = 1; c <= nb; c++)
            res = res * c;
    }
    return res;
}