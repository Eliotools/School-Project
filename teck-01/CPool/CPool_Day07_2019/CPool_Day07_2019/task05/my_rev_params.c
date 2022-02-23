/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** print params
*/
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    while (*str != '\0')
    {
        my_putchar(*str);
        str++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    while (argc != 0)
    {
        my_putstr(argv[argc - 1]);
        write(1, "\n", 1);
        argc--;
    }
    return (0);
}
