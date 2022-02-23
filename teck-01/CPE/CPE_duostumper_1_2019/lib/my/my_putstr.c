/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_putstr Piscine
*/

void my_putchar(char c);

int my_putstr_handler(int n, char const *str);

int my_putstr(char const *str)
{
    my_putstr_handler(0, str);
    return (0);
}

int my_putstr_handler(int n, char const *str)
{
    if (str[n] == '\0') {
        return (0);
    }
    my_putchar(str[n]);
    my_putstr_handler(n+1, str);
    return (0);
}