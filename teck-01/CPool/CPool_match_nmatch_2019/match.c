/*
** EPITECH PROJECT, 2019
** file_2
** File description:
** find_dif
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);

void  match(char const *s1, char const *s2)
{
    int i1 = 0;
    int j2 = 0;
    char *str;
    int k = 0;
    int y = my_strlen(s1);
    
    str = malloc(sizeof(char) * (y) + 1);
    while ((s1[i1] == s2[j2] || s2[j2] == '*') \
           && s2[j2] != '\0') {
        if (s2[j2] == '*') {
            j2++;
            while ( s2[j2] != s1[i1]) {
                str[k] = (s1[i1]);
                i1++;
                k++;
            }
        }
        if (s1[i1] == s2[j2]) {
            str[k] = (s1[i1]);
            k++;
        }
        i1++;
        j2++;
        }
    if (k == y)
        return('1');
    else
        return('0');
}

int main ()
{
    char *str = "AAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char *str_2 = "AAAAAAA*AAAAAAAAAA";

    match(str, str_2);
}

