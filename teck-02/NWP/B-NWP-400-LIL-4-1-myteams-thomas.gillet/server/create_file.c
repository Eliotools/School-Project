/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** create_file
*/

#include "server.h"

void create_file(char *filename)
{
    if (access(filename, F_OK ) != -1)
        return ;
    else {
        fopen(filename, "a+");
    }
}

void create_files(void)
{
    create_file(open_file("user"));
    create_file(open_file("teams"));
    create_file(open_file("thread"));
    create_file(open_file("channel"));
    create_file(open_file("replies"));
    create_file(open_file("private"));
}