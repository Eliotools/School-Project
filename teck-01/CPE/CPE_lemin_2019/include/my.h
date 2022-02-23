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
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "phoenix.h"
#include "printf.h"

typedef struct all {
    char **src;
    char s;
    char *top;
    int size;
    char *untop;
    int *way;
    char *next;
    char *old;
} all_t;

#ifndef My
#define My

char *add(char *src, char c);
char *delet(char *src, char c);
int *init_way(char *X, char c);
char *carentine(char *T, char *E);
int is_in(char *str, char c);
char *loop(all_t *all);
int **init_distance(char *X, char s);
int main(void);

#endif //My