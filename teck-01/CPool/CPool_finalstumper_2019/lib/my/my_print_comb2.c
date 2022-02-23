/*
** EPITECH PROJECT, 2024
** day03
** File description:
** Created by Leo Fabre
*/

void my_putchar(char);

int print_digits2(int x)
{
    char first;
    char sec;

    first = x / 10 + '0';
    sec = x % 10 + '0';
    my_putchar(first);
    my_putchar(sec);
    return (0);
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 1;

    while (a < 99) {
        b = a + 1;
        while (b < 100) {
            print_digits2(a);
            my_putchar(' ');
            print_digits2(b);
            if (a != 98 || b != 99) {
                my_putchar(',');
                my_putchar(' ');
            }
            b++;
        }
        a++;
    }
    return (0);
}