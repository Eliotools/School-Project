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
#include "printf.h"
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

char *my_strcat(char *rtl, char *nrj)
{
    char *new = malloc(sizeof(char) * (len(rtl) + len(nrj) + 1));
    int i = 0;
    int j = 0;
    for (;rtl[i] != '\0'; i++)
        new[i] = rtl[i];
    for (;nrj[j] != '\0'; i++, j++)
        new[i] = nrj[j];
    new[i] = '\0';
    return (new);
}

int glasses(char *buffer, char *test)
{
    int i = 0;
    if (len(buffer) == 0)
        return (0);
    while (buffer[i] != '\0' && test[i] != '\0') {
        if (buffer[i] != test[i]) {
            return (0);
        }
        i++;
    }
    return (1);
}

int executor(char *path, char *str, char **arg, char **env)
{
    pid_t pid;
    DIR *dir = opendir(path);
    struct dirent *readable = NULL;
    int i = 0;

    if (dir == NULL)
        return(69);
    while ((readable = readdir(dir)) != NULL) {
        if (glasses(readable->d_name, arg[0]) == 1) {
            str = my_strcat(str, arg[0]);
            if ((pid = fork()) == 0)
                execve(str, arg, env);
            wait(&i);
        }
    }
    return (0);
}

void my_pid(char **envp, char **path, char **arg)
{
    char *str;
    for (int i = 0; path[i]; i++) {
        str = my_strcat(path[i], "/");
        if (access(path[i], F_OK) == -1)
            i++;
        executor(path[i], str, arg, envp);
    }
}