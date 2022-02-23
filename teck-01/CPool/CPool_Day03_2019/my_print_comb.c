/*
** EPITECH PROJECT, 2019
** my_print_comb.c
** File description:
** displays digits
*/

#include <unistd.h>

void charcall(int a, int b, int c)
{
    while (c <= 57 )
    {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
        if (a <= 55 )
        {
            my_putchar(',');
            my_putchar(' ');
        }
        c += 1;
    }
}

int my_print_comb()
{
    int  a = 48;
    int  b = 49;
    int  c = 50;

    while (a <= 55)
    {
        while (b <= 56)
        {
            charcall (a,b,c);
            b += 1;
            c = b + 1;
        }
        b = a + 1;
        a += 1;
    }
    
}
