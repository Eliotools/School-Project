	/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** params
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar1(char c)
{
    write(1, &c, 1);
}

int my_putstr1(char const *str)
{
    while (*str != '\0') {
        my_putchar1(*str);
        *str++;
    }
    return (0);
}

int my_strlen1(char *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        i++;
        nb++;
    }
    return (nb);
}

char size_str(int argc, char **argv)
{
    int too_long = (argc - 1);
    int i = argc;

    while (i != 0) {
        too_long += my_strlen1(argv - 1);
        i--;
    }
    return (too_long);
}

char *concat_params(int argc, char **argv)
{
    int arg = 0;
    int kara = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * (size_str(argc, argv)));

    while (arg != argc) {
        while (argv[arg][kara] != '\0') {
            str[j] = argv[arg][kara];
            kara++;
            j++;
        }
        kara = 0;
        str[j] = '\n';
        j++;
        arg++;
    }
    return (str);
}
