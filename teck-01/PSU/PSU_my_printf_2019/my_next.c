/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** next
*/
#include "include/my.h"
#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void my_put_nbr_in_str (char new, int base);

int my_new_putstr(char const *str, int base);

void pourcent_p (va_list list)
{
    my_putstr("À faire");
}

void my_printf (char *str, ...)
{
    va_list list;
    int i = 0;
    int j = 0;
    int len = my_strlen(str);
    void (*point_fonc[])() = {&pourcent_id, &pourcent_id, &pourcent_s,
    &pourcent_c, &pourcent_b, &pourcent_S,
    &pourcent_, &pourcent_u, &pourcent_o,
    &pourcent_X, &pourcent_x, &pourcent_p};
    char tableau[13] = {'d', 'i', 's', 'c', 'b', 'S',
    '%', 'u', 'o', 'X', 'x', 'p', 0};

    va_start(list, str);
    while (i <= len) {
        while (str[i] != '%' && i <= len)
            my_putchar(str[i++]);
        for (; tableau[j] != str[i+1] && j <= 11; j++);
        (*point_fonc[j])(list);
    i += 2;
    }
    va_end(list);
}

int my_new_putstr(char const *str, int base)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < ' ' || str[i] >= 127) {
            my_putchar('\\');
            my_put_nbr_in_str(str[i], base);
        }
        else
            my_putchar(str[i]);
    }
    return 0;
}

void my_put_nbr_in_str (char new, int base)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (4));
    char other = new;
    char anotherone = base;

    result[3] = '\0';
    while (new != 0) {
        anotherone = new;
        new = new / base;
        other = anotherone % base;
        result[i] = other;
        i++;
    }
    result = my_revstr(result);
    my_putstr(result);
}