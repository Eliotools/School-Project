/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "include/my.h"

forme_t maker(char **array, forme_t forme)
{
    int fake = veri(array);

    if (fake == 0) {
        forme.is_good = 0;
    } else {
        forme.is_good = 1;
        forme = other(array, forme);
    }
    return (forme);
}

int veri(char **array)
{
    int compte = 0;
    for (; array[compte]; compte++);
    if (compte <= 1)
        return (0);
    for (int i = 0; array[0][i]; i++) {
        if (array[0][i] != ' ' && (array[0][i] < '0' || array[0][i] > '9'))
            return (0);
    }
    for (int j = 1; array[j]; j++) {
        for (int i = 0; array[j][i]; i++) {
            if (array[j][i] != ' ' && array[j][i] != '*') {
                return (0);
            }
        }
    }
    return (1);
}

forme_t other(char **array, forme_t forme)
{
    char **new = malloc(sizeof(char *) * (array[0][2])-48);
    for (int i = 0; i != (array[0][2])-48; i++) {
        new[i] = malloc(sizeof(char) * (array[0][0])-48);
        new[i] = array[i+1];
    }
    forme.color = array[0][4]-48;
    forme.forme = new;
    forme.compte = 0;
    forme.line = array[0][2]-48;
    forme.col = array[0][0]-48;

    return (forme);
}

int printer(forme_t *struc, touch_t *touch)
{
    variables_t variables;
    forme_t structur = (choose_struct(struc));
    char **other = split_string(readable("include/data/map"));

    variables = init_struc(variables);
    initscr();
    noecho();
    curs_set(FALSE);
    print_touch(split_string(readable("include/data/stat")), touch);
    variables.stop = getch();
    while (variables.stop == 'x') {
        variables.size =  find_size(structur.forme);
        variables.next = (choose_struct(struc));
        variables.drop = 0;
        variables.x = 10;
        variables.y = 2;
        structur = space_x(&variables, touch, &structur, other);
    }
    endwin();
    return (0);
}

int find_size(char **struc)
{
    int i = 0;

    while (struc[i])
        i++;
    return i;
}
