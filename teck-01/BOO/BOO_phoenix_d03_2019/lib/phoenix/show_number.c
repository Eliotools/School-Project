/*
** EPITECH PROJECT, 2019
** main
** File description:
** Moi
*/

void my_putchar(char c);

int show_number (int a)
{
    if (a = -2147483648)
        return (84);
    int negate = 0;
    int b = 0;

    if (a <= 9 && a >= 0)
        my_putchar(a + '0');
    if (a < 0) {
        my_putchar('-');
        a = a * -1;
        if (a <= 9 && a >= 0)
            my_putchar(a + '0');
    }
    if (a > 9) {
        b = a % 10;
        show_number (a / 10);
        my_putchar (b + '0');
    }
    return (0);
}