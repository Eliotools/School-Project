/*
** EPITECH PROJECT, 2024
** day03
** File description:
** Created by Leo Fabre
*/

void my_putchar(char);

int my_isneg(int nb)
{
    if (nb >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}