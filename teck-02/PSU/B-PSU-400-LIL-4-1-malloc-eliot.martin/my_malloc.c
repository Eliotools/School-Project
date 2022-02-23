/*
** EPITECH PROJECT, 2021
** B-PSU-400-LIL-4-1-malloc-eliot.martin
** File description:
** my_malloc
        mk
        export LD_LIBRARY_PATH=./my_malloc:$LD_LIBRARY_PATH
        gcc main.c -L. -l my_malloc
        a.out
*/
#include <stdio.h>

void *malloc(size_t nb)
{
    if (!nb)
        return NULL;
    void *base = sbrk(0);
    char *end = ((char*)base) + nb;
    brk(end);
    return (base);
}