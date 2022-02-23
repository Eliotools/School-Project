/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** str
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "../include/function.h"

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int my_strlen_w_spaces(char *str)
{
    int i = 0;
    int op = 0;

    for (i = 0; str[i] != '\0'; i++){
        if (str[i] != ' ')
            op++;
    } return (op);
}

void my_strcat(char *dest, char *str)
{
    int i = my_strlen(dest);

    for (int j = 0; str[j] != '\0'; j++)
        dest[j + i] = str[j];
}

int my_strcmp(char *name, char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != name[i])
            return (0);
    } return (1);
}

int my_atoi(char *str)
{
    int value = 0;
    int i = 0;

    if (str[0] == '-')
        i++;
    for (i; str[i] != '\0'; i++){
        if (str[i] >= '0' && str[i] <= '9')
            value = value * 10 + str[i] - '0';
    } if (str[0] == '-')
        return (-value);
    else
        return (value);
}