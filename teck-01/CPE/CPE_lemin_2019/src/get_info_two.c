/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_info_two
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "lemin.h"
#include "function.h"

int nbr_of_link(char *buffer)
{
    int nbr = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '-')
            nbr++;
    return (nbr);
}

int get_ant(char *buffer)
{
    char nbr[50];

    for (int i = 0; buffer[i] >= '0' && buffer[i] <= '9'; i++)
        nbr[i] = buffer[i];
    return (number(nbr));
}

int get_nbr_room(char *buffer)
{
    int nbr = 0;

    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '#'){
            for (; buffer[i] != '\n'; i++);
        }
        if (buffer[i] == ' '){
            for (; buffer[i] != '\n'; i++);
            nbr++;
        }
    }
    return (nbr);
}

int *get_nbr_link(char *buffer, int nbr_room, char **name)
{
    int i = 0;
    int *nbr = malloc(sizeof(int) * nbr_room);
    for (; buffer[i] != '-'; i++);
    for (; buffer[i] != '\n'; i--);
    i++;
    for (; buffer[i] != '\0'; i++){
        for (int j = 0; j < nbr_room; j++){
            if (buffer[i] == name[j][0]){
                nbr[j]++;
                i += 3;
            }
        }
    }
    return (nbr);
}