/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
** swap
*/
#include <unistd.h>

int my_evil_str (char *str)
{
    int y = 0;
    int x = 0;
    int c;
    
    while (str[x] != '\0')
    {
        x++;
    }
    x--;
    while (x > y)
    {
        c = str[y];
        str[y] = str[x];
        str[x] = c;
        x = x - 1;
        y = y + 1;
    }
    return (str);
}
