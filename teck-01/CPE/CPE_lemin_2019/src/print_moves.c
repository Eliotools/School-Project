/*
** EPITECH PROJECT, 2020
** print_moves.c
** File description:
** print moves
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"
#include "function.h"

void up(char *scheme, char **name, move_t *move, int j)
{
    if ((*move).state[j] <= len(scheme)){
        my_putchar('P');
        my_put_nbr(j + (*move).k);
        my_putchar('-');
        my_putchar(name[scheme[(*move).state[j + (*move).k - 1] - 1] - 48][0]);
        if (j <= (*move).nbr - 1)
            my_putchar(' ');
        (*move).state[j + (*move).k - 1]++;
    }
}

void down(char *scheme, char **name, move_t *move, int j)
{
    if ((*move).state[j - 1] <= len(scheme)){
        my_putchar('P');
        my_put_nbr(j);
        my_putchar('-');
        my_putchar(name[scheme[(*move).state[j - 1] - 1] - 48][0]);
        if (j <= (*move).nbr - 1)
            my_putchar(' ');
        (*move).state[j - 1]++;
    }
}

move_t up_and_down(char *scheme, char **name, move_t *move)
{
    for (int j = 1; j < (*move).nbr + 1; j++){
        if ((*move).lock == 1){
            up(scheme, name, move, j);
        } else{
            down(scheme, name, move, j);
        }
    }
    return (*move);
}

void final_print(char *scheme, int nb, char **name)
{
    if (len(scheme) % 2 == 1) {
        my_putchar('P');
        my_put_nbr(nb);
        my_putchar('-');
        my_putchar(name[scheme[len(scheme) - 1] - 48][0]);
        my_putchar('\n');
    }
}

void print_move(char *scheme, int nb, char **name)
{
    move_t move;
    move.nbr = 1;
    move.lock = 0;
    move.state = malloc(sizeof(int) * nb  +1);
    move.k = 0;
    for (int i = 0; i < nb + 1; i++)
        move.state[i] = 1;
    for (int i = 0; i < nb + 1; i++){
        move = up_and_down(scheme, name, &move);
        my_putchar('\n');
        if (move.nbr == nb)
            move.lock = 1;
        if (move.lock == 1){
            move.nbr--;
            move.k++;
        }
        else
            move.nbr++;
    }
    final_print(scheme, nb, name);
}
