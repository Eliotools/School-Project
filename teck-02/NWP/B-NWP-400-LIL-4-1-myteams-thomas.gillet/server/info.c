/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** user
*/

#include "server.h"

void info(server_t *serv, int i)
{
    switch (serv->client_pos[i]) {
        case 0 :
            info_user(serv, i);
            break;
        case 1 :
            info_bis("teams", serv, i);
            break;
        case 2 :
            info_bis("channel", serv, i);
            break;
        case 3 :
            info_bis("thread", serv, i);
            break;
    }
}

void info_user(server_t *serv, int i)
{
    char *line = get_line_by_uuid(serv->uuids[i], open_file("user"));
    char *line_scd = get_line_by_uuid(serv->uuids[i], open_file("user"));
    char *msg = malloc(512);

    sprintf(msg, "280 %s%s\"%c\"", take_uuid(line), take_name(line_scd),
    take_status(line));
    write(serv->current_sd, msg, strlen(msg));
}

void info_bis(char *fl, server_t *serv, int i)
{
    char *line;
    char *tmp = malloc(300);
    char *msg = malloc(512);
    for (int j = 0; (line = get_x_line(file_to_str(open_file(fl)), j+1))
        != NULL; j++) {
        strcpy(tmp, line);
        if (strcmp(add_quote(serv->pos_uuids[i]), take_uuid(tmp)) == 0) {
            if (strncmp(fl, "teams", 6) == 0)
                sprintf(msg, "281 %s%s%s", take_uuid(line), take_name(line),
                take_desc(tmp));
            if (strncmp(fl, "channel", 8) == 0)
                sprintf(msg, "282 %s%s%s", take_uuid(line), take_name(line),
                take_desc(tmp));
            if (strncmp(fl, "thread", 7) == 0)
                sprintf(msg, "283 %s%s%s%s%s", take_uuid(line),
                take_user_thread(get_x_line(file_to_str(open_file(fl)), j+1)),
                take_time_thread(get_x_line(file_to_str(open_file(fl)), j+1)),
                take_name(line) , take_desc(tmp));
        }
    } write(serv->current_sd, msg, strlen(msg));
}