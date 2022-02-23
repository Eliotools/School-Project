/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exec
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include "../include/function.h"

int my_exec(char **arg, char **envp)
{
    int pid;
    int status;
    int exit_s = 0;
    pid_t proces;
    for (int i = 0; arg[i]; i++)
        printf("arg[%d] = %s\n", i, arg[i]);
    pid = fork();
    if (pid == 0){
        proces = getpid();
        execve(arg[0], arg, envp);
        kill(proces, SIGKILL);
    }
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        exit_s = WIFEXITED(status);
    if (WTERMSIG(status) == SIGSEGV)
        my_printf("Segmentation fault (core dumped)\n");
    return (exit_s);
}