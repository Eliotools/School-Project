/*
** EPITECH PROJECT, 2024
** day03
** File description:
** Created by Leo Fabre
*/

void my_putchar(char);

void my_put_nbr(int nb)
{
    int modulo = 0;

    if (nb <= 9 && nb >= 0) {
        my_putchar(nb + '0');
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
        if (nb <= 9 && nb >= 0)
            my_put_nbr(nb);
    }
    if (nb > 9) {
        modulo = nb % 10;
        my_put_nbr(nb / 10);
        my_putchar(modulo + '0');
    }
}