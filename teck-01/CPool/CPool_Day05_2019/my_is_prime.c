/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** prime finder
*/

int my_is_prime (int nb)
{
    int y = nb - 1;

    while (y != 2)
    {
        if (nb % y == 0)
        {
            break;
        }
        y--;
    }
    if (nb % y == 0)
        return (0);
    else
        return (1);
}
