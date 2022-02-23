/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** strcpy
*/
#include <stdio.h>

char *my_strcpy (char *dest, char const *src)
{
    int i = 0;
    
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char main (void)
{
    char a[] = "eliot";
    char b[10] ;
    my_strcpy (a,b);
    printf ("%s",b);
}
