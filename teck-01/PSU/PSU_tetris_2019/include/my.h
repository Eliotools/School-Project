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
#include "printf.h"
#include "phoenix.h"

typedef struct forme {
    int is_good;
    char **forme;
    int col;
    int line;
    int compte;
    int nb;
    char *name;
    int color;
} forme_t;

typedef struct touch {
    int left;
    int right;
    int turn;
    int drop;
    int pause;
    int quit;
    int map;
    int debug;
    int level;
    char *size;
} touch_t;

typedef struct variables {
    int drop;
    int get;
    int x;
    int y;
    int stop;
    int size;
    forme_t next;
} variables_t;

#ifndef My
#define My

int is_alpha(char *str, char *src);
touch_t space_y(touch_t touch, char **av);
forme_t *alpha(forme_t *form);
void loop(void);
void print_tetri(forme_t struc);
char *name(char *str);
int nb_tetris(void);
char **take_option(int ac, char **av);
int next(int ac, char **av);
int main(int ac, char **av);
forme_t *fill_struc(void);
char **open_struc(forme_t *struc);
forme_t maker(char **array, forme_t forme);
int veri(char **array);
forme_t other(char **array, forme_t forme);
int printer(forme_t *struc, touch_t *touch);
forme_t choose_struct(forme_t *struc);
int find_size(char **struc);
void print_next(char **next, char *map, int nb);
char *modif_map(char **map, variables_t *variables, char **structur);
void debug(forme_t *struc, touch_t *touch);
char *str_fusion(char *big, char *small, int x);
touch_t take_touch(touch_t touch, char **av);
void print_struc(char **structy, variables_t *variables);
void print_touch(char **array, touch_t *touch);
touch_t fill_touch(touch_t touch);
void choose (variables_t *variables, touch_t *touch, char **other);
variables_t init_struc(variables_t variables);
forme_t space_x(variables_t *variables, touch_t *touch, \
forme_t *structur, char **other);
char *modifi(char *str);
void printt(char *str, int touch);
char **watch_line(char **other);
char **modif_all(char **map, int j);
forme_t *turn(forme_t *forme);
#endif //My


