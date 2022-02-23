/*
** EPITECH PROJECT, 2020
** mini
** File description:
** MOi
*/

#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "include/phoenix.h"
#include "include/printf.h"
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

char *my_strcat(char *rtl, char *nrj);
int glasses(char *buffer, char *test);
int executor(char *path, char *str, char **arg, char **env);
void my_pid(char **envp, char **path, char **arg);

void bit(char **envp, char *buffer, char **path)
{
    char **arg;
    if (glasses(buffer, "exit\n") == 1)
        exit(10);
    if (glasses(buffer, "env\n") == 1)
        show_string_array(envp);
    else {
        arg = str_to_word_array(buffer, ' ');
        my_pid(envp, path, arg);
    }
}

void next(char **envp, char **path)
{
    size_t size = 100;
    char *buffer = malloc(sizeof(char) * size);

    while(glasses(buffer, "exit\n") == 0) {
        getline(&buffer, &size, stdin);
        bit(envp, buffer, path);
        my_printf("$>");
    }
}

char *take_off_path(char *str)
{
    char *new = malloc(sizeof(char) * (len(str) - 5));
    int j = 5;

    for (int i = 0; str[j] != '\0'; i++, j++)
        new[i] = str[j];
    return(new);
}

char **find_path(char **envp)
{
    int i = 0;
    while (envp[i][0] != 'P' || envp[i][1] != 'A' || envp[i][2] != 'T' || envp[i][3] != 'H')
        i++;
    return (str_to_word_array(envp[i], ':'));
}

int main(int ac, char **av, char **envp)
{
    char **path = find_path(envp);
    if (ac != 1)
        return (84);

    my_printf("$>");
    path[0] = take_off_path(path[0]);
    next(envp, path);
}