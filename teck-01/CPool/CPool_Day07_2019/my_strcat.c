/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include <stdio.h>
#include <string.h>

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    char rev[100];
    int j = 0;

    for (i = 0 ; src[i] != '\0' ; i++)
        rev[i] = src[i];

    while (dest[j] != '\0')
    {
        rev[i] = dest[j];
        i++;
        j++;
    }

    rev[i] = '\0';
    printf("%s\n", rev);

    return (rev);
}
