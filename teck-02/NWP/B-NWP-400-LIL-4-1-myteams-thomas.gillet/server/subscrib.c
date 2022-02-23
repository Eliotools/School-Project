/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** subscrib
*/

#include "server.h"

void subscrib(server_t *serv, int i)
{
    char *uuid = get_second_word(serv->buffer);
    char *msg = malloc(400);

    if (get_line_by_uuid(uuid, open_file("teams")) != NULL) {
        if (teams_in_link(serv->uuids[i], remove_quote(uuid)) == -1) {
            print_by_uuid(serv->uuids[i], open_file("user"), uuid);
            server_event_user_subscribed(remove_quote(uuid),
            remove_quote(serv->uuids[i]));
            sprintf(msg, "311 %s%s", serv->uuids[i], uuid);
            write(serv->current_sd, msg, strlen(msg));
        } else {
            sprintf(msg, "313 %s%s", serv->uuids[i], uuid);
            write(serv->current_sd, msg, strlen(msg));
        }
    } else {
        sprintf(msg, "312 %s", uuid);
        write(serv->current_sd, msg, strlen(msg));
    }
}

int teams_in_link(char *user_uuid, char *teams_uuid)
{
    char *link;
    for (int k = 0; (link = get_nth(get_link("user",
    remove_quote(user_uuid)), k+1)) != NULL; k++)
        if (strcmp(link, teams_uuid) == 0)
            return (k);
    return (-1);
}

void subscribed(server_t *serv, int i)
{
    char *link;
    char *msg = malloc(400);
    char *li;
    char *desc = malloc(257);
    sprintf(msg, "320 ");
    for (int k = 0; (link = get_nth(get_link("user",
    remove_quote(serv->uuids[i])), k+1)) != NULL; k++) {
        li = get_line_by_uuid(add_quote(link), open_file("teams"));
        printf("line %s\n", li);
        strcpy(desc, li);
        strtok(desc, ":");
        desc = strtok(NULL, ":");
        desc = strtok(NULL, ",");
        printf("desc %s\n", desc);
        sprintf(msg, "%s\"%s\"%s%s", msg, link, take_name(li), desc);
    }
    write(serv->current_sd, msg, strlen(msg));
}

void subscribed_bis(server_t *serv, __attribute__((unused)) int i)
{
    char *uuid = get_second_word(serv->buffer);
    char *line;
    char *msg = malloc(400);

    sprintf(msg, "330 ");
    if (get_line_by_uuid(uuid, open_file("teams")) != NULL) {
        uuid = remove_quote(uuid);
        for (int t = 0; (line = get_x_line(file_to_str("user"), t+1))
        != NULL; t++)
            msg = subscribed_ter(line, uuid, msg);
    }
    write(serv->current_sd, msg, strlen(msg));
}

char *subscribed_ter(char *line, char *uuid, char *msg)
{
    printf("%s \n", line);
    char *tmp = malloc(strlen(line));
    char *name;
    char *link;
    char *user;

    strcpy(tmp, line);
    name = take_name(tmp);
    strcpy(tmp, line);
    user = take_uuid(line);
    for (int k = 0; (link = get_nth(get_link("user",
    remove_quote(user)), k+1)) != NULL; k++)
        if (strcmp(link, uuid) == 0)
            sprintf(msg, "%s%s%s\"%c\"", msg, user, name, take_status(tmp));
    return (msg);
}