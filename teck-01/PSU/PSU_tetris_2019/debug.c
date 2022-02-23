/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "include/my.h"

void debug(forme_t *struc, touch_t *touch)
{
    int nb = struc[0].nb;
    my_printf("*** DEBUG MODE ***\n");
    printt("Key Left :  ", touch->left);
    printt("Key Right :  ", touch->right);
    printt("Key Turn :  ", touch->turn);
    printt("Key Drop :  ", touch->drop);
    printt("Key Quit :  ", touch->quit);
    printt("Key Pause :  ", touch->pause);
    my_printf("Next :  ");
    if (touch->map == 1)
        my_printf("Yes\n");
    else if (touch->map == 0)
        my_printf("No\n");
    printt("Level :  ", touch->level);
    my_printf("Size :  %s\n", touch->size);
    my_printf("Teriminos :  %d\n", struc[0].nb+1);
    for (int i = 0; i <= nb ; i++)
        print_tetri(struc[i]);
    my_printf("Press any key to start Tetris\n");
    readable(stdin);
}

void printt(char *str, int touch)
{
    my_printf(str);
    if (touch != ' ')
        my_printf("%c\n", touch);
    else
    {
        my_printf("(space)\n");
    }
}

char *modifi(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            str[i] = '*';
    }
    return (str);
}

void print_tetri(forme_t struc)
{
    if (struc.is_good == 0) {
        my_printf("Tetriminos : Name %s : Error\n", struc.name);
    }
    else {
    my_printf ("Teriminos :  Name %s :  Size %d*%d : Color %d :\n", \
    struc.name, struc.col, struc.line, struc.color);
        for (int j = 0; struc.forme[j]; j++)
        {
            my_printf("%s\n", struc.forme[j]);
        }
    }
}

void loop(void)
{
    int i = 0;

    while (i == 0) {
        i = to_number(readable(stdin));
    }
}