/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** log
*/

#include "server.h"

void check_exist(server_t *serv, char *uuid, char *username, int i)
{
    if (uuid == NULL) {
        printf(INFOG "Adding user: %s" RESET "\n", username);
        uuid = gen_user_uuid();
        server_event_user_created(remove_quote(uuid), remove_quote(username));
        create_user(username, uuid);
        serv->usernames[i] = username;
        serv->uuids[i] = uuid;
        set_statete(username, '1');
        server_event_user_logged_in(remove_quote(uuid));
        printf(INFOG "State : %c\n" RESET, get_status(username));
    } else {
        printf(INFOG "FDP" RESET "\n");
        serv->usernames[i] = username;
        serv->uuids[i] = uuid;
        set_statete(username, '1');
        printf(INFOG "State : %c" RESET "\n", get_status(username));
        printf(INFOG "Teams : %s" RESET "\n", get_team(username));
        server_event_user_logged_in(remove_quote(uuid));
    }
}

void login_com(server_t *serv, int i)
{
    if (count_quotes(serv->buffer) != 2) {
        write(serv->current_sd, "505", 3);
        return;
    }
    char *username = get_second_word(serv->buffer);
    char *uuid = get_uuid(username);
    char *ret = malloc(512);

    check_exist(serv, uuid, username, i);
    if (uuid == NULL)
        uuid = get_uuid(username);
    serv->client_log[i] = 1;
    sprintf(ret, "331 %s %s\n", uuid, username);
    write(serv->current_sd, ret, strlen(ret));
}

void logout_com(server_t *serv, int i)
{
    printf(INFOG "Disconnecting client... %s" RESET "\n", serv->usernames[i]);
    if (serv->usernames[i] != NULL) {
        set_statete(serv->usernames[i], '0');
        server_event_user_logged_out(remove_quote(serv->uuids[i]));
    }
    serv->usernames[i] = NULL;
    serv->client_log[i] = 0;
    serv->pos_uuids[i] = NULL;
    serv->client_pos[i] = 0;
    write(serv->current_sd, "221", 3);
    close(serv->current_sd);
    serv->client_sockets[i] = 0;
}