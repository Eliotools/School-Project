/*
** EPITECH PROJECT, 2020
** match
** File description:
** Moi
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/phoenix.h"
#include "include/printf.h"

int take_line(int chop)
{
    size_t size = 100;
    char *buffer = malloc(sizeof(char) * size);
    int line = 0;

    while (line == 0){
        my_printf("Line: ");
        getline(&buffer, &size, stdin);
        line = to_number(buffer);
        if (line > chop) {
            my_printf("Error : this line is out of range\n");
            return (take_line(chop));
        }
        if (line < 1) {
            my_printf("Error: invalid input (positive number expected)\n");
            return (0);
        }
        else
            break;
    }
    return (line);
}

int take_matches(int chop)
{
    size_t size = 100;
    char *buffer = malloc(sizeof(char) * size);
    int matches = 0;

    while (1){
        my_printf("Matches: ");
        getline(&buffer, &size, stdin);
        matches = to_number(buffer);
        if (matches < 0 || matches > chop) {
            my_printf("Error: you cannot remove more than %d \
matches per turn\n", chop);
            return (take_matches(chop));
        }
        else
            break;
    }
    return (matches);
}

int show_array(char **str, int lenght)
{
    int i = 0;
    while (i != lenght+2)
    {
        show_string(str[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}

int show_numbers(int *str, int lenght)
{
    int i = 1;
    while (i != lenght+1)
    {
        show_number(str[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}

char *take_str(char *str, int col)
{
    static int stak = 1;
    int k = col/2;
    int a = k;
    int b = k;
    str[0] = '*';
    for (int i = 1; i != col + 1; i++)
        str[i] = ' ';
    for (; (a-b)/2 != stak;) {
        str[a] = '|';
        str[b] = '|';
        a = a + 1;
        b = b - 1;
    }
    str[k] = '|';
    str[col-1] = '*';
    stak++;
    return str;
}
