/*
** EPITECH PROJECT, 2024
** day03
** File description:
** Created by Leo Fabre
*/

void my_putchar(char);

int my_print_alpha(void)
{
    char c = 'a';

    while (c <= 'z') {
        my_putchar(c);
        c++;
    }
    return 0;
}