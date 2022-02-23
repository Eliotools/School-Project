/*
** EPITECH PROJECT, 2020
** navy
** File description:
** Moi
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "include/printf.h"
#include "include/phoenix.h"
#include "my.h"

void sendhit(char *shot, int enepid)
{
    int letter;
    int number;
    int go_letter;
    int go_number;

    go_letter = 0;
    go_number = 0;
    letter = shot[0] - 65;
    number = shot[1] - 49;
    while (go_letter != letter + 1)
        {
        kill(g_user2pid, SIGUSR1);
            usleep(1000);
            go_letter++;
        }
    while (go_number != number + 1)
        {
        kill(g_user2pid, SIGUSR2);
        usleep(1000);
        go_number++;
        }
    kill(g_user2pid, SIGUSR1);
}

void receiveinfo(char *shot,char **emap)
{
    int	i;

    i = 0;
    if (g_user2pid < 0)
        g_user2pid = g_user2pid * -1;
    my_putstr(shot);
    my_putstr(": ");
    signal(SIGUSR1, get_enepid1);
    signal(SIGUSR2, get_enepid_1);
    while (g_user2pid > 0) {
        pause();
        i++;
    } if (i == 2) {
        my_putstr("missed\n\n");
        emap[shot[1] - 49][shot[0] - 65] = 'o';
    } else if (i == 3)
    {
        my_putstr("hit\n\n");
        emap[shot[1] - 49][shot[0] - 65] = 'x';
    }
}