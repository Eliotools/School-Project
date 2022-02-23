/*
** EPITECH PROJECT, 2020
** head
** File description:
** print n start
*/

#include "head.h"
#include <stdio.h>

int buffer(void)
{
    char *buf = NULL;
    int res = 0;

    while (1) {
        buf = malloc(sizeof(char) * 4096);
        if (buf == NULL)
            return (84);
        res = read(0, buf, 4096);
        if (res == -1)
            return (84);
        buf[res] = '\0';
        my_putstr(buf);
        free(buf);
    }
    return (0);
}

args_t *args_rec(char *str, args_t *args)
{
    if (my_strcmp(str, "-c") == 0 || my_strcmp(str, "--bytes") == 0) {
        args->c = 1;
        args->n = 0;
        return (args);
    } if (my_strcmp(str, "-n") == 0 || my_strcmp(str, "--lines") == 0) {
        args->n = 1;
        args->c = 0;
        return (args);
    } if (my_strcmp(str, "-q") == 0 || my_strcmp(str, "--quiet") == 0
|| my_strcmp(str, "--silent") == 0) {
        args->q = 1;
        args->v = 0;
        return (args);
    } if (my_strcmp(str, "-v") == 0 || my_strcmp(str, "--verbose") == 0) {
        args->v = 1;
        args->q = 0;
        return (args);
    } args->nb_files += 1;
    return (args);
}

args_t *verif_args(int ac, char **av, args_t *args)
{
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[j]; j++) {
            if (av[i][j] < '0' || av[i][j] > '9')
                args = args_rec(av[i], args);
            else
                args->size = my_getnbr(av[i]);
        }
    }
    return (args);
}

args_t *init_struct(void)
{
    args_t *args = malloc(sizeof(args_t));

    if (args == NULL)
        return (NULL);
    int c = 0;
    int n = 0;
    int q = 0;
    int v = 0;
    int size = 0;
    char **files = NULL;
    int nb_files = 0;
    return (args);
}

int main(int ac, char **av)
{
    int err = 0;
    args_t *args = init_struct();

    if (args == NULL)
        return (84);
    if (ac == 1)
        return (buffer());
    else {
        args = verif_args(ac, av, args);
        return (main_loop(args, ac, av));
    }
}
