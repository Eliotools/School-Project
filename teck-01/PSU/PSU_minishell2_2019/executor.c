/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include "my.h"

int executor(char **arg, char **env)
{
    int pid;
    int status;
    int exit_s = 0;
    pid_t proces;

    pid = fork();
    if (pid == 0){
        proces = getpid();
        execve(arg[0], arg, env);
        exit;
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        exit_s = WIFEXITED(status);
    if (WTERMSIG(status) == SIGSEGV)
        my_printf("Segmentation fault (core dumped)\n");
    return (exit_s);
}

int my_pid(char **envp, char **path, char **arg)
{
    char *str = malloc(10000);
    for (int i = 0; path[i]; i++){
        str = path[i];
        my_strcat(str, arg[0]);
        str = my_strcat(str, "/");
        str = my_strcat(str, arg[0]);
        if (access(str, X_OK) == 0){
            arg[0] = str;
            executor(arg, envp);
            return (1);
        }
    }
    my_printf("%s: Command not found.\n", arg[0]);
    free (str);
    return (0);
}