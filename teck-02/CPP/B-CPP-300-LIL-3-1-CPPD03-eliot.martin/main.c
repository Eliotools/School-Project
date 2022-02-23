/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <stdio.h>
#include "string.h"

int  main(void)
{
    string_t s;
    string_t str;
    char * strr = "e";
    string_init(&s, "azHolloer");
    string_init(&str, "&é");
    s.insert_c(&s, 0, strr);
    printf("result = %s\n",s.str);
    string_destroy (&s);
    string_destroy (&str);
    return (0);
}
