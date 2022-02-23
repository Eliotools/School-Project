/*
** EPITECH PROJECT, 2019
** main
** File description:
** Moi
*/
#include "include/phoenix.h"
#include <stdio.h>

char *concat_strings (char *dest, char const *src);


void main (void)
{
    char str[10] = "eliot";
    char *str2 = "martin";
    printf("%s\n",concat_strings(str, str2));
}
