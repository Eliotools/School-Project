/*
** EPITECH PROJECT, 2019
** my_print_comb2
** File description:
**
*/

#include <unistd.h>



void display(int a, int b, int c, int d)
{
    my_putchar(a);
    my_putchar(b);
    my_putchar(' ');
    my_putchar(c);
    my_putchar(d);
    if (a == '9' && b == '8')
        my_putchar('\n');
    else {
        my_putchar(',');
        my_putchar(' ');
    }
    return;
}

void manage_addition(int a, int b,int c)
{
    for (int d = '1'; a <= '9' && b <= '9' && c <= '9'; d++) {
        display(a, b, c, d);
        if (b >= '9' && c >= '9' && d >= '9') {
            a++;
            b = '0';
            c = a;
            d = b;
        }
        if (c >= '9' && d >= '9') {
            b++;
            c = a;
            d = b;
        }
        if (d >= '9') {
            c++;
            d = '0';
        }
    }
    return;
}

int my_print_comb2(void)
{
    int a = '0';
    int b = '0';
    int c = '0';
    manage_addition(a, b, c);
    return (0);
}

