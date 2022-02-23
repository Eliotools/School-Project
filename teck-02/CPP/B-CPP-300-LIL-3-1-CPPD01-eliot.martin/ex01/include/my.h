/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include "printf.h"
#include "phoenix.h"

typedef struct used {
    int sup;
    int to_close;
    int clone_in;
    int clone_out;
    char **path;
} used_t;

int main(int av, char ac);