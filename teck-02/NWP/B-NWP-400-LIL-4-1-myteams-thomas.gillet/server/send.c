/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** send
*/

#include "server.h"

void message_received(server_t *serv, int i)
{
    (void) serv;
    (void) i;
}

char *check_uuid(char *uuid)
{
    char *line;
    for (int i = 0; (line = get_x_line(file_to_str(
        open_file("user")), i+1)) != NULL; i++)
        if (strcmp(take_uuid(line), uuid) == 0)
            return (line);
    return (NULL);
}
