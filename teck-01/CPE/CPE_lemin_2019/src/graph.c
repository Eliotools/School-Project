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

void get_infos_and_init(int k, char *buffer, t_info *info, char ***format)
{
    (*info) = main_info(buffer);
    (*format) = malloc(sizeof(char *) * info->nbr_rooms + 2);
    for (int i = 0; i < (*info).nbr_rooms + 2; i++)
        (*format)[i] = malloc(sizeof(char) * 100);
    (*format)[0] = check_index_2(start_end(buffer), (*info).name_of_rooms);
    for (int i = 0; i < (*info).nbr_rooms; i++)
        (*format)[1][i] = i + 48;
    for (int i = 0; i < (*info).nbr_rooms; i++){
        (*format)[i + 2][0] = i + 48;
        for (int j = 0, k = 0; (*info).link[i][j] != '\0'; j++, k++){
            (*format)[i + 2][k + 1] = check_index((*info).link[i][j],
                    (*info).name_of_rooms);
            j += 2;
        }
    }
    for (int i = 0; i < (*info).nbr_rooms + 2; i++){
        for (k = 0; (*format)[i][k + 1] != '\0'; k++);
        (*format)[i][k + 1] = '\n';
    }
}

int main(int ac, char **av)
{
    int k = 0;
    char *buffer = malloc(1024);

    if (ac != 1)
        return (84);
    if (read(0, buffer, 1024) < 1)
        return (84);
    if (error_handling(buffer) == 84) {
        return (84);
    }
    t_info info;
    char *scheme;
    char **format;
    get_infos_and_init(k, buffer, &info, &format);
    scheme = dijktra(format);
    if (scheme == NULL)
        return (84);
    output(buffer);
    print_move(scheme, info.nbr_ant, info.name_of_rooms);
    return (0);
}