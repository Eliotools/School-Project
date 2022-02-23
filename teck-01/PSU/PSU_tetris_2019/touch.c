/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "include/my.h"

touch_t fill_touch(touch_t touch)
{
    touch.left = 'j';
    touch.right = 'l';
    touch.drop = 'k';
    touch.turn = 't';
    touch.quit = 'q';
    touch.pause = ' ';
    touch.level = '1';
    touch.size = "20*10";
    touch.debug = 0;
    touch.map = 1;

    return (touch);
}

touch_t take_touch(touch_t touch, char **av)
{
    int j = 0;
    for (int i = 0; av[i]; i++, j++) {
        if ( my_strcmp(av[i], "-l") == 0 || \
        my_strcmp(av[i], "--left") == 0)
            touch.left = (av[i+1][1]);
        if ( my_strcmp(av[i], "-r") == 0 || \
        my_strcmp(av[i], "--right") == 0)
            touch.right = (av[i+1][3]);
        if ( my_strcmp(av[i], "-t") == 0 || \
        my_strcmp(av[i], "--turn") == 0)
            touch.turn = (av[i+1][3]);
        if ( my_strcmp(av[i], "-d") == 0 || \
        my_strcmp(av[i], "--drop") == 0)
            touch.drop = (av[i+1][3]);
    }
    touch = space_y(touch, av);
    return (touch);
}

void print_touch(char **array, touch_t *touch)
{
    mvprintw(LINES/2-3, COLS/2-5, (array[0]));
    mvprintw(LINES/2-2, COLS/2-5, (array[1]), touch->left);
    mvprintw(LINES/2-1, COLS/2-5, (array[2]), touch->right);
    mvprintw(LINES/2, COLS/2-5, (array[3]), touch->turn);
    mvprintw(LINES/2+1, COLS/2-5, (array[4]), touch->drop);
    mvprintw(LINES/2+2, COLS/2-5, (array[5]), touch->quit);
    mvprintw(LINES/2+3, COLS/2-5, (array[6]), touch->pause);
}

void choose (variables_t *variables, touch_t *touch, char **other)
{
    if (variables->drop == 0)
        variables->get = getch();
    if (variables->get == touch->right)
        if (other[variables->y][variables->x+2] != '|')
            variables->x++;
    if (variables->get == touch->left)
        if (other[variables->y][variables->x-1] != '|')
            variables->x--;
    if (variables->get == touch->quit)
        variables->stop = touch->quit;
    if (variables->get == touch->pause) {
        variables->get = 0;
        while (variables->get != touch->pause) {
            mvprintw(LINES/2, COLS/2, \
            ("Press '%c' to un pause\n"), touch->pause);
            variables->get = getch();
        }
    } if (variables->get == touch->drop)
        variables->drop = 1;
}

forme_t space_x(variables_t *variables, touch_t *touch, \
forme_t *structur, char **other)
{
    char *map = chartochar(other);

    while (variables->stop != touch->quit && \
    variables->y + variables->size !=  22 && \
    other[variables->y+variables->size-1][variables->x + 1] != '*' && \
    other[variables->y+variables->size-1][variables->x - 1] != '*')
    {
        clear();
        print_next(variables->next.forme, map, touch->map);
        print_struc(structur->forme, variables);
        choose(variables, touch, other);
        if (variables->get == touch->turn && structur->compte == 0) {
            variables->size = structur->line;
        }
        variables->y -= variables->size - 1;
        refresh();
    }
    map = modif_map(other, variables, structur->forme);
    return (variables->next);
}