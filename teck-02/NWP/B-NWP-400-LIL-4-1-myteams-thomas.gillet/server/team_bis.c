/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** team
*/
#include "server.h"

void create_team_bis(char *user_uuid, char **array, server_t *serv)
{
    char *uuid = gen_user_uuid();
    char *msg = malloc(400);
    char *everyone = malloc(400);

    if (name_is_existing(array[0], open_file("teams")) == 1) {
        printf(INFOG "%s %s %s" RESET "\n", uuid, array[0], array[1]);
        server_event_team_created(remove_chars(uuid, '\"'),
        remove_chars(array[0], '\"'), remove_chars(user_uuid, '\"'));
        create_team(array[0], array[1], uuid);
        sprintf(msg, "100 %s%s%s", uuid, array[0], array[1]);
        write(serv->current_sd, msg, strlen(msg));
        sprintf(everyone, "104 %s%s%s", uuid, array[0], array[1]);
        for (int y = 0; serv->client_sockets[y] != 0; y++) {
            write(serv->client_sockets[y], everyone, strlen(everyone));
        }
    } else
        write(serv->current_sd, "550", 3);
}

void create_channel_bis(char *user_uuid, char **array, server_t *serv)
{
    char *uuid = gen_user_uuid();
    char *msg = malloc(255);
    char *everyone = malloc(400);

    if (name_is_existing(array[0], open_file("channel")) == 1) {
        server_event_channel_created(remove_chars(user_uuid, '\"'),
        remove_chars(uuid, '\"'), remove_chars(array[0], '\"'));
        create_channel(array[0], array[1], uuid);
        print_by_uuid(add_quote(user_uuid), open_file("teams"), uuid);
        sprintf(msg, "101 %s%s%s", uuid, array[0], array[1]);
        write(serv->current_sd, msg, strlen(msg));
        sprintf(everyone, "105 %s%s%s", uuid, array[0], array[1]);
        for (int w = 0; serv->client_sockets[w] != 0; w++) {
            if (teams_in_link(serv->uuids[w], user_uuid) != -1) {
                write(serv->client_sockets[w], everyone, strlen(everyone));
                printf("one yes\n");
            }
        }
    } else
        write(serv->current_sd, "551", 3);
}

void create_thread_bis(char *user_uuid, char **array, server_t *serv, int i)
{
    char *uuid = gen_user_uuid();
    char *msg = malloc(255);
    int times = 0;

    printf(INFOG "Before all" RESET "\n");
    if (name_is_existing(array[0], open_file("thread")) == 1) {
        printf(INFOG "Before all" RESET "\n");
        server_event_thread_created(remove_quote(user_uuid),
        remove_quote(uuid), remove_quote(serv->uuids[i]),
        remove_quote(array[0]), remove_quote(array[1]));
        printf(INFOG "Before create" RESET "\n");
        times = create_thread(array[0], array[1], uuid, serv->uuids[i]);
        printf(INFOG "After create" RESET "\n");
        print_by_uuid(add_quote(user_uuid), open_file("channel"), uuid);
        sprintf(msg, "102 %s%s\"%d\"%s%s", uuid, serv->uuids[i], times,
        array[0], array[1]);
        write(serv->current_sd, msg, strlen(msg));
    } else
        write(serv->current_sd, "552", 3);
}

void create_reply_bis(char *user_uuid, char **array, server_t *serv, int i)
{
    char *uuid = gen_user_uuid();
    char *msg = malloc(255);
    int times = 0;

    server_event_reply_created(remove_chars(user_uuid, '\"'),
    remove_chars(serv->uuids[i], '\"'), remove_chars(array[0], '\"'));
    times = create_replies(array[0], uuid, serv->uuids[i]);
    print_by_uuid(add_quote(user_uuid), open_file("thread"), uuid);
    sprintf(msg, "103 %s%s\"%d\"%s", uuid, serv->uuids[i], times,
    array[0]);
    write(serv->current_sd, msg, strlen(msg));
}

char *take_uuid_no_quote(char *line)
{
    char *tmp = malloc(strlen(line));

    if (line == NULL)
        return (NULL);
    line = strtok(line, "\"");
    strcpy(tmp, line);
    return (tmp);
}