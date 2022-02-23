/*
** EPITECH PROJECT, 2019
** Moi
** File description:
** Encore Moi
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../include/printf.h"
#include "../../include/phoenix.h"

int len_buff(void)
{
    int offset = 0;
    char *buffer = stdout;
    int len = 0;

    while ((len = read(1, buffer + offset, 200 - offset))> 0){
        offset += len;
    }
    free (buffer);
}
