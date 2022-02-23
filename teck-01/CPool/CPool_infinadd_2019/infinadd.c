/*
** EPITECH PROJECT, 2019
** infinadd
** File description:
** calcul
*/


#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>

char *print_result(char *result, int stockage)
{
    if (stockage == 1)
        write(1, "1", 1);
    for (int p = 0; p <= my_strlen(result) - 2; p++) {
        my_putchar(result[p]);
    }
    my_putchar('\n');
    return (result);
    free(result);
}

int my_stockage(char *first, char *second)
{
    if (my_strlen(first) >= my_strlen(second))
        return (my_strlen(first));
    if (my_strlen(first) < my_strlen(second))
    return (my_strlen(second));
}

char *infinadd(char *first, char *second, int i, int j)
{
    int stockage = my_stockage(first, second) + 1;
    char *result = malloc(sizeof(char) * (stockage +1));
    int retenue = 0;

    while (i >= 0 || j >= 0) {
    if (retenue == 1) {
            result[stockage - 1] = first[i] + second[j] - 47;
            retenue = 0;
    }
        else result[stockage - 1] = first[i] + second[j] - 48;
    i--;
    j--;
    stockage--;
    if (result[stockage] > '9' && result[stockage] != '\0') {
            result[stockage] -= 10;
            retenue++;
    }
    }
    print_result(result, retenue);
}

int main(int ac, char **av)
{
    int i = my_strlen(av[1]);
    int j = my_strlen(av[2]);

    infinadd(av[1], av[2], i, j);
    return (0);
}