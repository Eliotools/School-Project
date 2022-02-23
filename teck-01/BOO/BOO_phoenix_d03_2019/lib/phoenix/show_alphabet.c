/*
** EPITECH PROJECT, 2019
** main
** File description:
** Moi
*/

#include <stdio.h>

void my_putchar(char c);

int show_alphabet(void)
{
    int c = 97;

    for (int i = 0; i < 26; i++, c++)
        my_putchar(c);
    my_putchar('\n');
    return (0);
}