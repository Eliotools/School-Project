/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** recup_arg
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include "../include/function.h"

int recup_nbr_of_word(char *av)
{
    int i = 0;
    int nbr_of_words = 0;

    for (int j = 0; av[j] != '\0'; j++){
        if ((av[j] != ' ' && av[j] != ':' && av[j] != '\n') && i == 0){
                nbr_of_words++;
                i = 1;
            }if (av[j] == ' ' || av[j] == ':')
                i = 0;
    }
    return (nbr_of_words);
}

char *recup_word(char *av)
{
    int i = 0;
    int good = 0;
    int start = 0;
    char *str = malloc(sizeof(char) * my_strlen(av));

    for (int j = 0; av[j] != '\0'; j++){
        if (av[j] != ' ' && av[j] != '\t'){
            if (good == 1 && start == 1)
                str[i++] = ' ';
            str[i++] = av[j];
            start = 1;
            good = 0;
            } if (av[j] == ' ' || av[j] == '\t')
                good = 1;
    }
    return (str);
}

char *recup_separate_arg(char *av)
{
    static int i = 0;
    int j = 0;
    char *str = malloc(my_strlen(av));

    for (i, j = 0; av[i] != ' ' ; i++, j++){
        if (av[i] == '\n'){
            i = -1;
            break;
        }
        str[j] = av[i];
    }
    i++;
    return (str);
}

int verif_get(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' ' && str[i] != '\n')
            return (1);
    }
    return (0);
}

char **recup_arg(void)
{
    int i = 0;
    size_t size;
    char *str = malloc(sizeof(char) * 1000);
    int value = 0;
    while (value < 2){
        value = 0;
        my_printf("\033[31mmarvin_il_test_pas>\033[0m");
        value = getline(&str, &size, stdin);
        if (value == -1) exit (0);
        if (verif_get(str) == 0)
            value = 0;
    } int nbr_of_arg = recup_nbr_of_word(str);
    char **arg = malloc(1000);
    str = recup_word(str);
    for (i = 0; i < nbr_of_arg; i++){
        arg[i] = recup_separate_arg(str);
    }
    arg[i] = NULL;
    return (arg);
}