/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** task02 Day04
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        *str++;
    }
    return (0);
}
