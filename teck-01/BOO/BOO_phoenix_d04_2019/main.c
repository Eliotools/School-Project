/*
** EPITECH PROJECT, 2019
** main
** File description:
** Moi
*/
#include "include/phoenix.h"
#include <stdio.h>

char *duplicate_string(char const *src);
char **split_string(char const *str);
int show_string_array (char *const *array);
char **split_string(char const *str);

int  main()
{
    char test_word_array [] = "eliot 47 martin    le+++fou";
    show_string_array(split_string(test_word_array));
}