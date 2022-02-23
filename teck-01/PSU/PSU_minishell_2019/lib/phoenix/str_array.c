/*
** EPITECH PROJECT, 2020
** str_array
** File description:
** Moi
*/

#include "../../include/phoenix.h"
#include <stdlib.h>

char **str_to_word_array(char *str, char c)
{
    int i = 1;
    int k = 0;
    char **array;

    for (int m = 0; str[m] != '\0'; m++)
        if (str[m] == c)
            i++;
    array = malloc(sizeof(char *) * i+1);
    for (int j = 0; j != i; j++)
        array[j] = malloc (sizeof(char) * 10);
    i = 0;
    for (int e = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            e = 0;
            k++;
        } else {
            array[k][e] = str[i];
            e++;
        }
    } array[k + 1] = 0;
    return array;
}