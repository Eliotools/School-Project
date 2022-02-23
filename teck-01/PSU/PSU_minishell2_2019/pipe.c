/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include "my.h"

void piping(char *str, used_t *used)
{
    int k = 0;

    k = open("nothing", O_RDWR | O_CREAT, 0644);
    dup2 (k, 1);
    my_printf(str);
    close (k);
    set_std(used);
    k = open("nothing", O_RDWR);
    dup2(k, 0);
    used->sup = 1;
}