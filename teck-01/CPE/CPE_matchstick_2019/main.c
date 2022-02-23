/*
** EPITECH PROJECT, 2019
** main
** File description:
** Moi
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/phoenix.h"
#include "include/printf.h"

char **take_array(int line);
int *take_number(char **array, int line);
int show_array(char **str, int lenght);
int take_line(int chop);
int take_matches(int chop);
int take_all_number(int *number, int line);

char *array_turn(char *str, int matches, int *number, int line)
{
    int i = 0;
    int j = 0;
    if (matches <= number[line]){
        for (;str[i] != '|'; i++);
        i += number[line];
        i--;
        while (j != matches)
        {
            str[i] = ' ';
            i--;
            j++;
        }
        number[line] -= matches;
    }
    else
        my_printf("Error: not enough matches on this line\n");

    return str;
}

char **ia_turn(char **array, int *number, int line)
{
    int i = 0;

    for (; number[i] < 1 ; i++)
        if (i > line)
            break;
    array[i] = array_turn(array[i], 1, number, i);
    my_printf("\nAI's turn...\nAI removed 1 match(es) from line %d\n", i);
    return (array);
}

char **player_turn(char **array, int matches, int *number, int line)
{
    int lili = 0;
    int mama = 0;
    int *cheker = take_number(array, line);

    number = take_number(array, line);
    my_printf("\nYour turn:\n");
    while (cheker[lili] == number[lili]) {
        number = take_number(array, line);
        lili = take_line(line);
        mama = take_matches(matches);
        if (lili == 0 || mama == 0) {
            array[0] = "0";
            return array;
        } array[lili] = array_turn(array[lili], mama, number, lili);
    }
    my_printf("Player removed %d match(es) from line %d\n", mama, lili);
    return array;
}

int next(int line, int matches, char **array)
{
    int *number = take_number(array, line);
    int toto = take_all_number(number, line);

    while (toto != 0)
    {
        show_array(array, line);
        array = player_turn(array, matches, number, line);
        number = take_number(array, line);
        if (array[0][0] == '0')
            return(0);
        if ((toto = take_all_number(number, line)) == 0)
            return (2);
        show_array(array, line);
        array = ia_turn(array, number, line);
        toto = take_all_number(number, line);
        number = take_number(array, line);
        if ((toto = take_all_number(number, line)) == 0)
            return (1);
    }
    return 0;
}

int main(int ac, char **av)
{
    int result = 0;
    char **array;

    if (ac != 3)
        return (84);
    if ((to_number(av[1]) >= 100 && to_number(av[1]) <= 1) || \
(to_number(av[2]) < 1 || to_number(av[1]) < 1))
        return 84;
    array = take_array(to_number(av[1]));
    result = next (to_number(av[1]), to_number(av[2]), array);
    show_array(array, to_number(av[1]));
    if (result == 1)
    {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (result);
    } if (result == 2) {
        my_printf("You lost, too bad...\n");
        return (result);
    }
    return (result);
}