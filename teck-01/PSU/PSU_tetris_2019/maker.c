/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include "include/my.h"

int nb_tetris(void)
{
    int nb = 0;
    DIR *other = opendir ("./tetriminos");
    struct dirent *new;
    new = readdir(other);
    while ((new = readdir(other)) != NULL) {
        if (new->d_name[0] != '.')
            nb++;
    }
    closedir (other);
    return (nb);
}

char *name(char *str)
{
    char *new = malloc(sizeof(char *) * len(str));
    int i = 0;

    while (str[i] != '.') {
        new[i] = str[i];
        i++;
    }
    return (new);
}

forme_t *alpha(forme_t *form)
{
    forme_t clone;
    int count = form[0].nb;
    int i = 0;
    int j = 0;

    for (i = 0; i <= count; i++) {
        for (j = i + 1; j <= count; j++){
            if (is_alpha(form[i].name, form[j].name) > 0){
                clone = form[i];
                form[i] = form[j];
                form[j] = clone;
            }
        }
    }
    return (form);
}

int is_alpha(char *str, char *src)
{
    for (int i = 0; str[i] || src[i]; i++)
    {
        if (str[i] > src[i])
            return (1);
        if (str[i] < src[i])
            return (-1);
    }
    return (1);
}

touch_t space_y(touch_t touch, char **av)
{
    for (int i = 0; av[i]; i++) {
        if ( my_strcmp(av[i], "-w") == 0 || \
        my_strcmp(av[i], "--without-next") == 0)
            touch.map = 0;
        if (strcmp(av[i], "-D") == 0 || \
        strcmp(av[i], "--debug") == 0)
            touch.debug = 1;
        if (strcmp(av[i], "-L") == 0 || \
        strcmp(av[i], "--level") == 0)
            touch.level = (av[i+1][0]);
        if (strcmp(av[i], "--map-size") == 0)
            touch.size = modifi(av[i+1]);
        if ( my_strcmp(av[i], "-q") == 0 || \
        my_strcmp(av[i], "--quit") == 0)
            touch.quit = (av[i+1][3]);
        if ( my_strcmp(av[i], "-p") == 0 || \
        my_strcmp(av[i], "--pause") == 0)
            touch.pause = (av[i+1][3]);
    }
    return (touch);
}