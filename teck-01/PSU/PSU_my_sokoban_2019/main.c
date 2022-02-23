/*
** EPITECH PROJECT, 2019
** Main.c
** File description:
** Moi
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#define BUFF_SIZE 10000

char **put_in_array(char* buffer, int col, int line )
{
    int i = 0;
    int j = 0;
    int k = 0;
    char** array = malloc(sizeof(char*)* line);
    while (buffer[i] != '\0') {
        array[k] = malloc(sizeof(char)*col);
        j = 0;
        while(buffer[i] != '\n')
        {
            array[k][j] = buffer[i];
            i++;
            j++;
        }
        array[k][j] = '\0'; 
        k++;
        i++;
    }
    array[k] = NULL;
    next(array);
    return;
}

char funding_p (char **map)
{
    int i = 0;
    int j = 0;
    while (map[j][i] != 'P' || map[j][i] != '\0') {
        if (map[j][i] = '\n') {
            i = 0;
            j++;
        }
        i++;
    }
    printf ("x = %d\n y = %d",i,j);
}

int next(char ** array)
{   
    int i = 0;
    char ** copy = array;
    while (1) {
        for (i = 0;array[i] != NULL; i++) {
            mvprintw(i, 1, array[i]);
            refresh();
        }
        //funding_p(array);
        if (getch() == '+') 
            break;
    }
    return 0;
}

char* fs_open_file(char const *filepath)
{
    initscr();
    int i;
    int nb_line;
    int compte;
    char buffer[BUFF_SIZE];
    int j = 0;

    i = open(filepath, O_RDONLY);
    if (i == -1){
        return (84);
    } else {
        read(i, buffer, BUFF_SIZE);
    }
    put_in_array(buffer, getmaxx(stdscr), getmaxy(stdscr));
    endwin();
    close(i);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        return (84);
    }
    char *buffer = fs_open_file(argv[1]);
}