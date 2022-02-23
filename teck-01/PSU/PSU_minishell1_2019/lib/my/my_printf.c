/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** write everyting
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

void display_var(char type, va_list *list);

int my_printf(char *s, ...);

int recup_nb_of_var(char *s);

char *int_binaire(int value);

char *int_hexa_maj(int value);

void display_type(char type, va_list *list);

char *int_hexa_min(int value);

int int_octal(int value);

int *string_octal(char *sr);

int int_simple_octal(int value);

int my_printf(char *s, ...)
{
    int i = 0;
    int j = 0;
    int var = 0;
    va_list list;

    va_start(list, s);
    var = recup_nb_of_var(s);
    for (; var > 0; var--, j = 0, i += 2) {
        for (; s[i] != '%'; i++, j++)
            my_putchar(s[i]);
        if (s[i + 1] == 'l' && s[i + 2] == 'd'){
            display_type('!', &list);
            i++;
        } else
            display_type(s[i + 1], &list);
    }
    for (; s[i] != '\0'; i++, j++)
        my_putchar(s[i]);
    va_end(list);
    return (0);
}

int recup_nb_of_var(char *s)
{
    int var = 0;
    int i = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%' && (s[i + 1] == 'd' || 'c' ||
                            's' || 'S' || 'b'))
            var++;
    }
    return (var);
}

void display_type(char type, va_list *list)
{
    char c;

    if (type == 'd' || type == 'i')
        my_putnbr(va_arg(*list, int));
    if (type == 'o')
        int_simple_octal(va_arg(*list, int));
    if (type == 's')
        my_putstr(va_arg(*list, char *));
    if (type == 'c') {
        c = (char)va_arg(*list, int);
        my_putchar(c);
    } if (type == '!')
        my_putnbr(va_arg(*list, long));
}

int *string_octal(char *sr)
{
    for (int i = 0; sr[i] != '\0'; i++) {
        if (sr[i] < '!' || sr[i] > '~')
            int_octal(sr[i]);
        else
            my_putchar(sr[i]);
    }
    return (0);
}
