/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/
#include <stdlib.h>

struct info_param *space_x(char **av, int i, int ac)
{
    struct info_params *thing = malloc(sizeof(struct info_params) * (ac));

    thing[i].lenght = len(av[i]);
    thing[i].str = av[i];
    thing[i].copy = duplicate_string(av[i]);
    thing[i].word_array = split_string(av[i]);
}

struct info_param *paramaters_to_array(int ac, char **av)
{
    int i = 0;
    while (i != ac)
    {
        space_x(av, i, ac);
        i++;
    }
}