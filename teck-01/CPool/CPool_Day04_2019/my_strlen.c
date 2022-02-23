/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** str
*/
#include <unistd.h>

int my_strlen (char const *str )
{
    int i = 1;
    
    while (*str != '\0')
    {
        str++;
            i++;
    }
    return(i);
}

