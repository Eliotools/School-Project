/*
** EPITECH PROJECT, 2020
** graph.c
** File description:
** graph
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "graph.h"
#include "lemin.h"
#include "function.h"

int main(int ac, char **av)
{
    int i = 0;
    char *buffer = malloc(1024);
    t_info info = init(info);

    if (ac != 1)
        return (84);
    if (read(0, buffer, 1024) < 1)
        return (84);
    if (buffer == NULL)
        return (84);
    printer("#number_of_ants\n", get_ant(buffer));
    info.check = check(buffer);
    info.nbr_rooms = get_nbr_room(buffer);
    for (int i = 0; i < info.nbr_rooms; i++)
        info.name_of_rooms[i] = get_name(buffer);
    info.name_of_rooms[i + 1] = NULL;
    printer_str("#rooms\n##start\n", info.name_of_rooms[0]);
    for (int i = 1; i <info.nbr_rooms; i++)
        printer_str("\n", info.name_of_rooms[i]);
    info.nbr_of_link = get_nbr_link(buffer, info.nbr_rooms, info.name_of_rooms);
    info.link = get_link(buffer, info.nbr_rooms, info.name_of_rooms);
}

t_info init (t_info info)
{
    info.nbr_ant = 0;
    info.nbr_rooms = 0;
    info.check = 0;
    return (info);
}

void printer(char *str, int nb)
{
    if (nb == 0)
        exit;
    my_put_str(str);
    my_put_nbr(nb);
}

void printer_str(char *str, char *src)
{
    if (src == NULL)
        exit;
    my_put_str(str);
    my_put_str(src);
}