/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** command
*/

#include "server.h"

void read_commands(server_t *serv)
{
    char *tab[MAX_COMMAND + 1] = {"/login", "/logout", "/logout\n",
        "/send", "/create", "/use", "Message_received", "/user", "/users\n",
        "/users", "/list\n", "/info\n", "/messages", "/subscribe",
        "/subscribed\n", "/subscribed", "/unsubscribe", "/help\n", "0"};

    for (int i = 0; i < MAX_CLIENTS; i++) {
        serv->current_sd = serv->client_sockets[i];
        if (FD_ISSET(serv->current_sd, &serv->fds)) {
            commands(serv, i, tab);
        }
    }
}

void commands(server_t *serv, int i, char **tab)
{
    int j;
    void (*point_fonc[])() = {&login_com, &logout_com, &logout_com, &send_com,
        &creat_zone, &use, &message_received, &user, &users, &users, &list,
        &info, &message_com, &subscrib, &subscribed, &subscribed_bis,
        &unsubscribe, &help, &unknown_command};
    serv->buffer = malloc(256);
    char *cmd = malloc(256);
    set_buffer(serv, i);
    memcpy(cmd, serv->buffer, 256);
    strtok(cmd, " ");
    for (j = 0; strcmp(cmd, tab[j]) != 0 && j < MAX_COMMAND; j++);
    if (j == 0 || j == 1 || j == 2 || j == MAX_COMMAND || j == MAX_COMMAND-1)
        (*point_fonc[j])(serv, i);
    else if (j != 0 && serv->client_log[i] == 1)
        (*point_fonc[j])(serv, i);
    else
        write(serv->current_sd, "502\n", 4);
    free(serv->buffer);
    free(cmd);
}

void create_message(char *send_uuid, char *recv_uuid, char *message)
{
    FILE *fp;
    char *line = malloc(256);

    sprintf(line, "sender_uuid:%s,receiver_uuid:%s,message:\"%s\",\
timestamp:\"%d\";\n", send_uuid, recv_uuid, message, (int)time(NULL));
    fp = fopen(open_file("private"), "a" );
    fprintf(fp, "%s", line);
    free(line);
    fclose(fp);
}

void send_com(server_t *serv, __attribute__((unused)) int i)
{
    char *uuid = NULL;
    char *message = NULL;
    char *reply = malloc(256);
    char *cmd = malloc(256);
    int x = 0;
    strcpy(cmd, serv->buffer);
    uuid = get_second_word(serv->buffer);
    if (check_uuid(uuid) == NULL) {
        sprintf(reply, "404 %s\n", uuid);
        write(serv->current_sd, reply, strlen(reply)); return;
    }
    message = get_third_word_noq(cmd);
    for (x = 0; x < MAX_CLIENTS; x++)
        if (strncmp(uuid, serv->uuids[x], 36) == 0) break;
    create_message(serv->uuids[i], uuid, message);
    server_event_private_message_sended(remove_chars(serv->uuids[i], '\"'),
    remove_chars(uuid, '\"'), message);
    sprintf(reply, "203 %s \"%s\"\n", serv->uuids[i], message);
    write(serv->client_sockets[x], reply, strlen(reply));
    write(serv->current_sd, "202", 3);
}

void unknown_command(server_t *serv, int i)
{
    (void) i;
    write(serv->current_sd, "500", 3);
}