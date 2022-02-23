/*
** EPITECH PROJECT, 2019
** main
** File description:
** Moi
*/
#include "include/phoenix.h"

char *next (char **ac)
{
    int i = 0;
    int j = 0;
    char *str = ac[1];
    char *src = ac[2];

    while (str[i] != '\0') {
        if (src[j] == '\0')
            return ("0\n");
        if (str[i] == src[j])
            i++;
        j++;
    }
    return ("1\n");
}

int main (int ac, char **av)
{
    if (ac != 3)
        return (84);
    else
        printf("%s\n",next(av));
    return (0);
}