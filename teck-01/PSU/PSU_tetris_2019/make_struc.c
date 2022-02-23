/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "include/my.h"

void print_next(char **next, char *map, int nb)
{
    mvprintw(0, 0, map);
    if (nb == 0)
        for (int i = 0; next[i]; i++)
            mvprintw(2+i, 26, next[i]);
}

forme_t choose_struct(forme_t *struc)
{
    int i = randomizer(struc[0].nb);

    if (struc[i].is_good == 1)
        return (struc[i]);
    else
    return (choose_struct(struc));
}

void print_struc(char **structy, variables_t *variables)
{
    for (int i = 0; structy[i]; i++) {
        mvprintw(variables->y, variables->x, (structy[i]));
        variables->y++;
    }
}

char *modif_map(char **map, variables_t *variables, char **structur)
{
    int i = 0;

    for (int j = 0;structur[i] && j != 4; i++, j++)
        str_fusion(map[variables->y + i - 1], structur[i], variables->x);
    return (chartochar(map));
}

char *str_fusion(char *big, char *small, int x)
{
    for (int i = 0; small[i]; i++)
    {
        big[x] = small[i];
        x++;
    }
    return (big);
}