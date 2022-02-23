/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** find str
*/
#include <stdio.h>

char *my_strstr (char *str, char const *find)
{
    char *comeback_str;
    comeback_str = str;
    int i = 0;
    char counter[10];
    int a = 0;

    while (*find != '\0')
    {
        str = comeback_str;
        while (*str != '\0')
        {
            if (*find == *str)
            {
                counter[a] = *str;
                a++;
            }
            str++;
        }
        find++;
    }
    printf ("%s", counter);
}

void main (void)
{
    char str[] = "bonsoir j'aime bien les pates";
    char find [] = "bon";
    my_strstr(str, find);
}
