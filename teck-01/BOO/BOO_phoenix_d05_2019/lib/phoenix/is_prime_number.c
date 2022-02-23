/*
** EPITECH PROJECT, 2019
** phoenix
** File description:
** Moi
*/

int is_prime_number(int nb)
{
    int clone = nb/2;

    if (nb == 2)
        return (1);
    for (; clone > 1; clone--)
        if ((nb % clone) == 0)
            return (1);
    return (0);
}