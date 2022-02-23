/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(const char *str);

char *my_strcat(char *s1, char *s2)
{
    char *str3 = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
    int i = 0;
    int x = 0;

    for (int i = 0; s1[i]; i++, x++)
        str3[x] = s1[i];
    for (int i = 0; s2[i]; i++, x++)
        str3[x] = s2[i];
    str3[x] = '\0';
    return (str3);
}