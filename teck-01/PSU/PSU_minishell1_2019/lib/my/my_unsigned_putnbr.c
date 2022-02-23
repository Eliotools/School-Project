/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Print a number give in main
*/

#include <unistd.h>

int my_putstr(char const *str);

void my_putchar(char c);

void my_unsigned_putnbr(unsigned int nb)
{
    if (nb < 0)
        my_unsigned_putnbr(4294967295 - nb + 1);
    if (nb >= 10) {
        my_unsigned_putnbr(nb / 10);
        my_unsigned_putnbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}
