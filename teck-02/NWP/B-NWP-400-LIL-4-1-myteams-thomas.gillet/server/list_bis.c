/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** list
*/

#include "server.h"

void list_channel(server_t *serv, int i)
{
    char *uuid;
    char *line = malloc(255);
    char *desc = malloc(MAX_DESCRIPTION_LENGTH + 2);
    char *name = malloc(MAX_NAME_LENGTH + 2);
    char *user = malloc(39);
    char *msg = malloc((MAX_DESCRIPTION_LENGTH + MAX_NAME_LENGTH + 43) * 20);

    sprintf(msg, "261 ");
    for (int k = 0; (uuid = get_nth(get_link("teams",
        serv->pos_uuids[i]), k+1)) != NULL; k++){
        line = get_line_by_uuid(add_quote(uuid), open_file("channel"));
        name = take_name(line);
        uuid = take_uuid(line);
        desc = take_desc(line);
    sprintf(msg, "%s%s%s%s", msg, uuid, name, desc);
    }
    write(serv->current_sd, msg, strlen(msg));
}

char *get_info_thread(char *uuid)
{
    char *tmp_uuid;
    char *line = malloc(1024);
    char *desc = malloc(MAX_DESCRIPTION_LENGTH + 2);
    char *name = malloc(MAX_NAME_LENGTH + 2);
    char *user = malloc(50);
    char *tmp_user = malloc(39);
    char *time = malloc(14);
    char *msg = malloc((MAX_DESCRIPTION_LENGTH + MAX_NAME_LENGTH + 43) * 20);

    line = get_line_by_uuid(add_quote(uuid), open_file("thread"));
    user = take_user_thread(line);
    for (int i = 0; i < 39; i++)
        tmp_user[i] = user[i];
    time = take_time_thread(get_line_by_uuid(add_quote(uuid),
    open_file("thread")));
    name = take_name(line);
    tmp_uuid = take_uuid(line);
    desc = take_desc(line);
    sprintf(msg, "%s%s%s%s%s", tmp_uuid, tmp_user, time, name, desc);
    return msg;
}

void list_thread(server_t *serv, int i)
{
    char *uuid;
    char *msg = malloc((MAX_DESCRIPTION_LENGTH + MAX_NAME_LENGTH + 43) * 20);

    sprintf(msg, "262 ");
    for (int k = 0; (uuid = get_nth(get_link
    ("channel", serv->pos_uuids[i]), k+1)) != NULL; k++)
        sprintf(msg, "%s%s", msg, get_info_thread(uuid));
    write(serv->current_sd, msg, strlen(msg));
}

void list_replies(server_t *serv, int i)
{
    char *uuid;
    char *line = malloc(255);
    char *desc = malloc(MAX_DESCRIPTION_LENGTH + 2);
    char *name = malloc(MAX_NAME_LENGTH + 2);
    char *time = malloc(14);
    char *msg = malloc((MAX_DESCRIPTION_LENGTH + MAX_NAME_LENGTH + 43) * 20);

    sprintf(msg, "263 ");
    for (int k = 0; (uuid = get_nth(get_link
    ("thread", serv->pos_uuids[i]), k+1)) != NULL; k++){
        line = get_line_by_uuid(add_quote(uuid), open_file("replies"));
        time = take_time_replies(get_line_by_uuid(add_quote(uuid),
        open_file("replies")));
        name = take_name(line);
        uuid = take_uuid(line);
        desc = take_desc(line);
        sprintf(msg, "%s%s%s%s%s", msg, add_quote(serv->pos_uuids[i]),
        desc, time, name);
    }
    write(serv->current_sd, msg, strlen(msg));
}
