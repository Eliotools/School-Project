/*
** EPITECH PROJECT, 2019
** Phoenix
** File description:
** Moi
*/
#include "phoenix.h"
#include <stdlib.h>

int mega_len(char **str, int k)
{
    int compte = 0;

    for (int i = 1; i < k; compte += len(str[i]), i++);
    compte += k-2;
    return (compte);
}

char *space_x(int argc, char **argv, char *str)
{
    int i = 1;
    int j = 0;
    int k = 0;

    while (i < argc) {
        while (argv[i][j] != '\0') {
            str[k] = argv[i][j];
            j++;
            k++;
        }
        j = 0;
        i++;
        if (i != argc) {
            str[k] = '\n';
            k++;
        }
    }
    return (str);
}

char *concat_parameters(int argc, char **argv)
{
    char *str = malloc(sizeof(char) * mega_len(argv, argc));

    if (argc == 1)
    {
        return (0);
    }
    str = space_x(argc, argv, str);
    return (str);
}