/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** check_fct
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "../include/function.h"

int check_fct(char **str, char **envp)
{
    if (my_strcmp("cd", str[0]) && my_strlen(str[0]) == 2){
        my_cd(str, envp);
        return (1);
    } if (my_strcmp("exit", str[0]) && my_strlen(str[0]) == 4){
        my_exit(str);
        return (1);
    } if (my_strcmp("setenv", str[0]) &&  my_strlen(str[0]) == 6) {
        my_setenv(str, envp);
        return (1);
    } if (my_strcmp("env", str[0]) && my_strlen(str[0]) == 3) {
        my_env(envp);
        return (1);
    } if (my_strcmp("unsetenv", str[0]) && my_strlen(str[0]) == 8) {
        my_unsetenv(str, envp);
        return  (1);
    } return (0);
}

char *recup_separate_path(char *av)
{
    static int i = 0;
    int j = 0;
    char *str = malloc(1000);

    for (i, j = 0; av[i] != ':'; i++, j++){
        if (av[i] == '\0'){
            i = -1;
            break;
        }
        str[j] = av[i];
    }
    i++;
    str[j] = '/';
    return (str);
}

char **recup_path(char **envp)
{
    char *path_one = malloc(1000);
    char **path = malloc(10000);
    int m = 0;
    int nbr_of_path = 0;

    for (int i = 0; envp[i] != NULL; i++){
        if (my_strcmp(envp[i], "PATH=")){
            for (int j = 0; envp[i][j + 5] != '\0'; j++)
            path_one[j] = envp[i][j + 5];
        }
    }
    nbr_of_path = recup_nbr_of_word(path_one);
    for (m = 0; m < nbr_of_path; m++)
        path[m] = recup_separate_path(path_one);
    path[m] = NULL;
    return (path);
}

int try_and_exec(char **arg, char **envp)
{
    char **path = malloc(10000);
    char *tmp_path = malloc(1000);

    path = recup_path(envp);
    for (int i = 0; path[i] != NULL; i++){
        tmp_path = path[i];
        my_strcat(tmp_path, arg[0]);
        printf("tmp_path = %s\n", tmp_path);
        if (access(tmp_path, X_OK) == 0){
            arg[0] = tmp_path;
            my_exec(arg, envp);
            return (1);
        }
    }
    return (0);
}