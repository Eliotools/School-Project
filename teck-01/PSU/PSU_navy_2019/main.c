/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "include/printf.h"
#include "include/phoenix.h"
#include "my.h"

extern int      g_user2pid;

static void	now(int sig, siginfo_t *siginfo, void *context)
{
    g_user2pid = siginfo->si_pid;
}

int finding_error(char **array)
{
    int k = 0;
    for (int i = 0; i <= 3; i++) {
        k = 0;
        if (array[i][k] >= '1' && array[i][k] <= '9' && array[i][k+3] >= '1' &&
array[i][k+3] <= '9' && array[i][k+6] >= '1' && array[i][k+6] <= '9')
                k++;
        if (array[i][k] == ':' && array[i][k+3] == ':')
                k++;
        if (array[i][k] >= 'A' && array[i][k] <= 'Z' &&
array[i][k+3] >= 'A' && array[i][k+3] <= 'Z')
                k++;
        if (k != 3)
            return (84);
    }
    return (0);
}

void filling(char *pos, char **map)
{
    char k = pos[0];
    char *first = filler(pos, first, 2, 3);
    char *second = filler(pos, second, 5, 6);
    if (first[0] == second[0]){
        if (first[1] < second[1])
            space_x(first, second, map, k);
        else
            space_x(second, first, map, k);
    }
    else
        if (first[0] < second[0])
            space_y(first, second, map, k);
        else
            space_y(second, first, map, k);
}

int connecting (int pid)
{
    struct sigaction another;

    my_printf("my_pid:\t%d\n", getpid());
    if (pid == 0) {
        my_printf("waiting for enemy connexion...\n\n");
        another.sa_flags = SA_SIGINFO;
        another.sa_sigaction = &now;
        sigaction(SIGUSR1, &another, NULL);
        pause();
        my_printf("enemy connected\n\n");
    }
    else {
        g_user2pid = pid;
        if (kill(pid, SIGUSR1) != -1)
            my_printf("successfully connected\n\n");
        else
            return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 1)
        return (84);
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            my_printf(readable("usage"));
        else {
            i = finding_error(split_string(readable(av[1])));
            if (i == 84)
                return (i);
            i = next(split_string(readable(av[1])), 0);
            if (i == 84)
                return (i);
        }
    }
    if (ac == 3) {
        next(split_string(readable(av[2])), to_number(av[1]));
    }
    return (0);
}