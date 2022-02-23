/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** list
*/

#include "server.h"

void list(server_t *serv, int i)
{
    switch (serv->client_pos[i]) {
        case 0 :
            list_team(serv);
            break;
        case 1 :
            list_channel(serv, i);
            break;
        case 2 :
            list_thread(serv, i);
            break;
        case 3 :
            list_replies(serv, i);
            break;
    }
}

void list_team(server_t *serv)
{
    char *line;
    char *uuid = malloc(39);
    char *desc = malloc(MAX_DESCRIPTION_LENGTH + 2);
    char *name = malloc(MAX_NAME_LENGTH + 2);
    char *msg = malloc((MAX_DESCRIPTION_LENGTH + MAX_NAME_LENGTH + 43) * 20);

    sprintf(msg, "260 ");
    for (int i = 0; (line = get_x_line(file_to_str(open_file("teams")),
        i+1)) != NULL; i++) {
            name = take_name(line);
            uuid = take_uuid(line);
            desc = take_desc(line);
            sprintf(msg, "%s%s%s%s", msg, uuid, name, desc);
    }
    write(serv->current_sd, msg, strlen(msg));
}

char *get_link(char *file_fs, char *uuid)
{
    char *line = get_line_by_uuid(add_quote(uuid), open_file(file_fs));
    line = strtok(line, ":");
    line = strtok(NULL, ":");
    line = strtok(NULL, ":");
    line = strtok(NULL, ":");
    if (strncmp(file_fs, "thread", 7) == 0){
        line = strtok(NULL, ":");
        line = strtok(NULL, ":");
    }
    return (line);
}

char *take_link(char *line)
{
    line = strtok(line, ":");
    line = strtok(NULL, ":");
    line = strtok(NULL, ":");
    line = strtok(NULL, ":");

    return (line);
}