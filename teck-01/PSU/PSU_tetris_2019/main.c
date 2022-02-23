/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "include/my.h"

char **take_option(int ac, char **av)
{
    int j = 0;
    char **option = malloc(sizeof(char *) * ac);
    for (int i = 0; i != ac; i++) {
        if (av[i][0] == '-') {
            option[j] = malloc(sizeof(char) * len(av[i]));
            option[j] = av[i];
            j++;
        }
    }
    option[j] = NULL;
    return (option);
}

int next(int ac, char **av)
{
    forme_t *struc = fill_struc();
    touch_t touch = fill_touch(touch);
    char **option = take_option(ac, av);

    for (int i = 0; option[i] != NULL; i++) {
        if (strcmp(option[i], "--help") == 0) {
            my_printf(readable("include/data/usage"));
            return (0);
        }
    }
    struc = alpha(struc);
    touch = take_touch(touch, av);
    if (touch.debug == 1)
        debug(struc, &touch);
    printer(struc, &touch);
    return (0);
}

int main(int ac, char **av)
{
        return (next(ac, av));
}

forme_t *fill_struc(void)
{
    int nb = nb_tetris();
    forme_t *struc = malloc(sizeof(forme_t) * nb+1);

    for (int i = 0; i != nb+1 ; i++ ) {
        struc[i] = maker(open_struc(&struc[i]), struc[i]);
        struc[i].nb = nb;
    }

    return (struc);
}

char **open_struc(forme_t *struc)
{
    static int consty = 0;
    DIR *other = opendir ("./tetriminos");
    struct dirent *new;

    new = readdir(other);
    for (int i = 0; i != consty && new->d_name[0] != '.'; i++)
    {
        new = readdir(other);
        while (new->d_name[0] == '.')
            {
                new = readdir(other);
            }
    }
    consty++;
    struc->name = name(new->d_name);
    return (split_string(readable(my_strcat("./tetriminos/", new->d_name))));
}