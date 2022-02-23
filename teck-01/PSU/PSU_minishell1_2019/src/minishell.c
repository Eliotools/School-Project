/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "../include/function.h"

void cat_some_things(char **arg, char **env, char *str, int i)
{
    my_strcat(str, arg[1]);
    my_strcat(str, "=");
    if (arg[2] != NULL)
        my_strcat(str, arg[2]);
    env[i] = str;
    env[i+1] = NULL;
    str = NULL;
}

int try_or_not_found(char **arg, char **envp)
{
    if (arg[0][0] == '.' && arg[0][1] == '/'){
        my_exec(arg, envp);
        return (1);
    } else {
        my_printf("%s: Command not found.\n", arg[0]);
        return (0);
    }
}

int main(int ac, char **av, char **envp)
{
    if (ac != 1)
        return (84);
    char **arg = malloc(1000);
    int total = 0;
    for (int i = 0; envp[i] != NULL; i++)
        total += my_strlen(envp[i]);
    char **env = malloc(sizeof(char) * total + 1000);
    env = envp;
    int state = 0;

    while (1) {
        state = 0;
        arg = recup_arg();
        state = check_fct(arg, env);
        if (state != 1)
            state = try_and_exec(arg, env);
        if (state != 1)
            try_or_not_found(arg, env);
    }
}