/*
** EPITECH PROJECT, 2024
** day03
** File description:
** Created by Leo Fabre
*/

void my_putchar(char);

void my_put_nbr(int);

int count_digits(int n)
{
    int digits = 0;

    while (n != 0) {
        n /= 10;
        digits++;
    }
    return (digits);
}

int get_digit(int n, int pos)
{
    pos--;
    while (pos != 0) {
        n /= 10;
        pos--;
    }
    return (n % 10);
}

int compare_digits(int i, int number, int digits)
{
    int first;
    int second;

    for (int j = 1; j <= digits; j++) {
        if (i == j)
            continue;
        first = get_digit(number, i);
        second = get_digit(number, j);
        if ((first == second) || (j > i && second > first))
            return (0);
    }
    return (1);
}

int print_num(int number, int digits, int first)
{
    int d = count_digits(number);

    for (int i = 1; i <= digits; i++) {
        if (compare_digits(i, number, digits) == 0)
            return (0);
    }
    if (first == 0) {
        my_putchar(',');
        my_putchar(' ');
    }
    while (d < digits) {
        my_putchar('0');
        d++;
    }
    if (number != 0)
        my_put_nbr(number);
    return (1);
}

int my_print_combn(int n)
{
    int number = 0;
    int max_value = 1;
    int max_digits = 0;
    int i = 0;
    int first = 1;

    while (i < n) {
        max_value *= 10;
        i++;
    }
    max_digits = count_digits(max_value) - 1;
    while (number < max_value) {
        if (print_num(number, max_digits, first))
            first = 0;
        number++;
    }
    my_putchar('\n');
    return (0);
}