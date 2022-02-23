/*
** EPITECH PROJECT, 2024
** day03
** File description:
** Created by Leo Fabre
*/

void my_putchar(char);

int my_print_digits(void)
{
    char c = '0';

    while (c <= '9') {
        my_putchar(c);
        c++;
    }
    return 0;
}