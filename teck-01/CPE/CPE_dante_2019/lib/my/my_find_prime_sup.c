/*
** EPITECH PROJECT, 2024
** day05
** File description:
** Created by Leo Fabre
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int res = nb;
    for (;my_is_prime(res) != 0; ++res)
        return (res);
    return nb;
}