/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** get_all_info
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "lemin.h"
#include "function.h"

t_info init_info(int link, int nbr, int big)
{
    t_info info;
    info.nbr_ant = 0;
    info.nbr_rooms = 0;
    info.link = malloc(sizeof(char *) * link);
    info.nbr_of_link = malloc(sizeof(int) * link);
    info.name_of_rooms = malloc(sizeof(char *) * nbr);
    for (int i = 0; i < link; i++){
        info.link[i] = malloc(sizeof(char) * (link * 2));
    }
    for (int i = 0; i < link; i++){
        info.name_of_rooms[i] = malloc(sizeof(char) * big);
    }
    return (info);
}

char *get_name(char *buffer)
{
    static int i = 0;
    int j = 0;
    char *name = malloc(sizeof(char) * 50);

    if (i == 0){
        for (i = 0; buffer[i] != '\n'; i++);
        i++;
    }
    for (; buffer[i] != '\0'; i++){
        if (buffer[i] == '#'){
            for (; buffer[i] != '\n'; i++);
            i++;
        } if (buffer[i] == ' '){
            for (; buffer[i] != '\n'; i++);
            i++;
            return (name);
        } name[j++] = buffer[i];
    }
    return (NULL);
}

void add_link(char *link, int index, char buf)
{
    (void)index;
    int i = 0;
    for (i = 0; link[i] != '\0'; i++);
    link[i] = buf;
    link[i + 1] = ' ';
}

char **get_link(char *buffer, int nbr, char **name)
{
    int i = 0;
    char **link = malloc(sizeof(char *) * nbr);
    for (int j = 0; j < nbr; j++)
        link[j] = malloc(sizeof(char) * 15);
    for (; buffer[i] != '-'; i++);
    for (; buffer[i] != '\n'; i--);
    i++;
    for (; buffer[i] != '\0'; i++){
        for (int j = 0; j < nbr; j++){
            if (buffer[i] == name[j][0]){
                add_link(link[j], i, buffer[i + 2]);
                i += 2;
                break;
            }
        }
    }
    return (link);
}

t_info main_info(char *buffer)
{
    int i = 0;
    t_info info = init_info(nbr_of_link(buffer), get_nbr_room(buffer), 5);

    info.nbr_ant = get_ant(buffer);
    info.nbr_rooms = get_nbr_room(buffer);
    for (i = 0; i < info.nbr_rooms; i++)
        info.name_of_rooms[i] = get_name(buffer);
    info.name_of_rooms[i + 1] = NULL;
    info.nbr_of_link = get_nbr_link(buffer, info.nbr_rooms, info.name_of_rooms);
    info.link = get_link(buffer, info.nbr_rooms, info.name_of_rooms);
    return (info);
}