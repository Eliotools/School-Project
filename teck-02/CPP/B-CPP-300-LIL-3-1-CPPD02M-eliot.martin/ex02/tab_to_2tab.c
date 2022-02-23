/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void  tab_to_2dtab(const  int *tab , int  length , int width , int  ***res)
{
    int compte = 0;
    int ** new = malloc(sizeof(int *) * length);

    for (int i = 0; i < length; i++) {
        new[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            new[i][j] = tab[compte];
            compte++;
        }
    }
    *res = new;
}