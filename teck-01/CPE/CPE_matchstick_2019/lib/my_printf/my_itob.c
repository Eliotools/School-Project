/*
** EPITECH PROJECT, 2019
** my_itob
** File description:
** int to binary
*/
#include <stdlib.h>
#include "../../include/printf.h"
#include "../../include/phoenix.h"

char *my_new_realloc(char *save, int size)
{
    int i = 0;
    char *final = malloc(sizeof(char) * (size + 1));

    final[size] = '\0';

    while (save[i] != save[size-1]) {
        final[i] = save[i];
        i++;
    }
    return (final);
}

char *itob(unsigned int to_convert)
{
    int i = 1;
    char *result = "0";

    while (to_convert/2 != 1)
    {
    result = my_new_realloc(result, i);
    result[i-1] = to_convert%2 + '0';
    to_convert = to_convert/2;
    i++;
    }
    for (int j = 0; j != 2; j++) {
    result = my_new_realloc(result, i);
    result[i-1] = to_convert%2 + '0';
    to_convert = to_convert/2;
    i++;
    }
    result = reverse_string(result);
    return (result);
}

void pourcent_p(va_list list)
{
    show_string("À faire");
}