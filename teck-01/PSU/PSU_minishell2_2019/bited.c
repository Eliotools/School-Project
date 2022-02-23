/*
** EPITECH PROJECT, 2020
** mini
** File description:
** MOi
*/

#include "my.h"

void my_setenv(char **env, char **buffer)
{
    int i = 0;
    int size = 0;

    for (; buffer[size]; size++);
    if (size == 1) {
        my_print_env(env);
        return;
    }
    if (size > 3){
        my_printf("setenv :Too many arguments.\n");
        return;
    }
    for (; env[i]; i++) {
        if (my_strcmp(env[i], buffer[1], '\0') == 0) {
            mod(env, buffer, i, size);
            return;
        }
    }
    mod(env, buffer, i, size);
    env[i + 1] = NULL;
}

void mod(char **env, char **str, int i, int size)
{
    char *new;

    str[1] = my_strcat(str[1], "=");
    if (size != 2)
        str[1]  = my_strcat(str[1], str[2]);
    new = str[1];
    new = deleted(new, '\n');

    env[i] = new;
    return;
}

char **my_unsetenv(char **env, char **buffer)
{
    int line = 0;

    if (buffer[1] == NULL){
        my_printf("unsetenv: Too few arguments.\n");
        return (NULL);
    }
    for (int j = 0; buffer[j]; j++) {
        for (int i = 0; env[i]; i++){
            if (my_strcmp(env[i], buffer[j], '=') == 0)
                line = i;
        }
        env[line] = "z";
    }
    return (env);
}

char *deleted(char *src, char c)
{
    int j = 0;
    if (len(src) -1 < 0)
        return (NULL);
    char *new = verif_m(sizeof(char) * len(src)-1);
    for (int i = 0; src[i]; i++, j++) {
        if (src[i] != c)
            new[j] = src[i];
        else
            j--;
    }
    return (new);
}

void my_exit(char **buffer)
{
    int size;

    for (size = 0; buffer[size]; size++);
    if (size == 1) {
        my_printf("exit\n");
        exit(0);
    } if (size > 2)
        my_printf("exit\nminishell: exit: too many arguments\n");
    buffer[1] = deleted(buffer[1], '\n');
    for (int i = 0; i != len(buffer[1]); i++)
        if (buffer[1][i] < 48 || buffer[1][i] > 57){
            my_printf("exit: Expression Syntax.\n");
            return;
        }
    size = to_number(buffer[1]);
    my_printf("exit\n");
    exit (size);
}