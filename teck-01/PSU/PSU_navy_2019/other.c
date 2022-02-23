/*
** EPITECH PROJECT, 2020
** otger
** File description:
** Moi
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "include/printf.h"
#include "include/phoenix.h"
#include "my.h"

char **decoding_pos(char *pos, char **map)
{
    int i = pos[0] - 48;
    char k = pos[0];
    int j = 0;
    char *geo = malloc(sizeof(int) * 2);
    if (i < 9)
        j = finding_twice(pos);
    if ( i > 2 && i < 6)
        filling(pos, map);
    geo[0] = pos[j] - 16;
    geo[1] = pos[j+1];
    pos[j] = '0';
    maper(geo, map, k);
    map[1][2] = '-';
    return (map);
}

int next(char **pos, int pid)
{
        int j = 0;
        int i = 999;
        char **map = split_string(readable("map"));
        char **emap = split_string(readable("map"));
        char *asking = malloc(sizeof(char) * 2);

        connecting(pid);
        asking[0] = '0';
        for (int i = 0; i != 8; i++)
            map = decoding_pos(pos[i/2], map);
        while (1) {
            show_map(map, emap);
            j = getline(&asking, &i, stdin);
            if (j == -1)
                return (84);
            my_printf("%c%c: ", asking[0], asking[1]);
            asking[0] = asking[0] - 16;
            maper(asking, map, 'o');
        }
}

void show_map( char **map, char **emap)
{
    my_printf("my position:\n");
    show_string_array(map);
    my_printf("\nenemy's positions:\n");
    show_string_array(emap);
    my_printf("\nattack: ");
}