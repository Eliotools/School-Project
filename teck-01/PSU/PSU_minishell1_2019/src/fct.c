/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** fct
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "../include/function.h"

void my_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++){
        if (env[i] != "z")
            my_printf("%s\n", env[i]);
    }
}

int my_setenv(char **arg, char **env)
{
    int line = 0;
    int i = 0;
    char *str = malloc(10000);

    if (arg[1] == NULL){
        my_env(env);
        return (0);
    } if (arg[3] != NULL){
        my_printf("setenv: Too many arguments.\n");
        return (-1);
    } for (i = 0; env[i] != NULL; i++){
        if (my_strcmp(env[i], arg[1]) == 1){
            line = i;
            change_env(env, arg, line);
            return (0);
        }
    }
    cat_some_things(arg, env, str, i);
}

void change_env(char **env, char **arg, int line)
{
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(arg[1]) + sizeof(char)
    * my_strlen(arg[2]) + 1);

    my_strcat(str, arg[1]);
    my_strcat(str, "=");
    if (arg[2] != NULL)
        my_strcat(str, arg[2]);
    env[line] = str;
    return ;
}

void my_unsetenv(char **arg, char **env)
{
    int line = 0;
    int j = 0;

    if (arg[1] == NULL){
        my_printf("unsetenv: Too few arguments.\n");
        return ;
    }
    for (int j = 0; arg[j] != NULL; j++) {
        for (int i = 0; env[i] != NULL; i++){
            my_printf("env[i] = %s\n", env[i]);
            if (my_strcmp(env[i], arg[j]) == 1) line = i;
        }
    }
    env[line] = "z";
}

int my_exit(char **arg)
{
    int value = 0;

    if (arg[1] == NULL){
        my_printf("exit\n");
        exit (0);
    }if (arg[2] != NULL) {
        my_printf("exit\n");
        my_printf("minishell: exit: too many arguments\n");
    } for (int i = 0; arg[1][i] != '\0'; i++){
            if (!(arg[1][i] >= 48 && arg[1][i] <= 57)){
            my_printf("exit: Expression Syntax.\n");
            return (-1);
        }
    }
    value = my_atoi(arg[1]);
    write(1, "exit\n", 5);
    exit (value);
}