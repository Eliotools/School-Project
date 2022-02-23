/*
** EPITECH PROJECT, 2019
** Phenix
** File description:
** Moi
*/

void my_putchar(char c);

void printable (int a, int b, int c)
{
    if (a != b && b != c && c != a)
    {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
        my_putchar(',');
        my_putchar(' ');
    }
}

void space_x( int a, int b, int c)
{

    while (a != '7') {
        printable(a, b, c);
        c++;
        if (c > '9')
        {
            b++;
            c = b+1;
        }
        if (b > '8') {
            a++;
            b = a+1;
            c = b+1;
        }
    }
}

int show_combinations(void)
{
    int a = '0';
    int b = '1';
    int c = '2';

    space_x(a, b, c);
    my_putchar('7');
    my_putchar('8');
    my_putchar('9');
}