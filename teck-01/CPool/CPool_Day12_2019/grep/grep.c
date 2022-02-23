/*
** EPITECH PROJECT, 2019
** grep.c
** File description:
** grep
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include <stdio.h>
#include <uchar.h>

int space_x (int fd, int ac)
{
    if (fd == -1) {
        my_putstr("Error with open\n");
        return (1);
    }
    if (ac < 2) {
        my_putstr("Missing argument");
        return (1);
    }
}
int main(int ac, char *av[])
{
    int fd;
    char buffer[30000];
    int size;
    int i = 2;
    int j = ac;
    char find[] = av[1]

    while (i != j) {
        fd = open(av[i], O_RDONLY);
        if (    fd == -1 || ac < 2 ) {
            return(space_x (fd, ac));
        }
        size = read(fd, buffer, 30000);
        write(1, buffer, size); 
        i++;
    }
    close(fd);
    return (0);
}