/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "../include/function.h"

int my_cd_normal(char *path)
{
    if (chdir(path) == -1){
        my_printf("%s: No such file or directory.\n", path);
        return (0);
    }
}

char *recup_home(char **env)
{
    char *str = malloc(1000);
    char *path = malloc(1000);

    my_strcat(path, "/home/");
    for (int i = 0; env[i] != NULL; i++){
        if (my_strcmp(env[i], "USER=")){
            for (int j = 0; env[i][j + 5] != '\0'; j++)
            str[j] = env[i][j + 5];
        }
    }
    my_strcat(path, str);
    free(str);
    return (path);
}

int my_cd(char **av, char **env)
{
    char *buffer = malloc(1024);
    static char *old_2_pwd;
    static char *old_pwd;
    if (av[1] == NULL){
        old_pwd = getcwd(buffer, 1024);
        my_cd_normal(recup_home(env));
        return (0);
    } if (av[1][0] == '-' && my_strlen(av[1]) == 1){
        old_2_pwd = getcwd(buffer, 1024);
        chdir(old_pwd);
        old_pwd = old_2_pwd;
        return (1);
    } else if (av[2] != NULL){
        my_printf("cd: Too many arguments.\n");
        return (-1);
    } else {
        old_pwd = getcwd(buffer, 1024);
        my_cd_normal(av[1]);
        return (0);
    }
}