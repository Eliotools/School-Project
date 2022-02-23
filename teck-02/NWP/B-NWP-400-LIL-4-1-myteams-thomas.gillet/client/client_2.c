/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** client_2
*/

#include "client.h"

int get_nb_messages(char **msg)
{
    int i;

    for (i = 0; msg[i] != NULL; i++);
    return (i);
}

char *get_message(char *line)
{
    char *tmp = malloc(strlen(line) + 1);

    strcpy(tmp, line);
    tmp = strtok(tmp, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ",");
    return (tmp);
}

void send_msg(client_t *cli, char *otheruuid)
{
    char **msgsent;
    char **msgreceived;
    char **allmsg;

    msgsent = get_msg_sent(cli->uuid, otheruuid);
    msgreceived = get_msg_recv(cli->uuid, otheruuid);
    allmsg = merge_messages(msgsent, msgreceived);
    if (allmsg[0] == NULL)
        printf("dommage\n");
    for (int u = 0; allmsg[u] != NULL; u++) {
        client_private_message_print_messages(
            remove_chars(take_first_uuid(allmsg[u]), '\"'),
            get_time_stamp(allmsg[u]),
            remove_chars(get_message(allmsg[u]), '\"'));
    }
}

void send_create_code(char *msg, client_t *cli, char **arr)
{
    char buffer[1024];
    if (strncmp("100", msg, 3) == 0)
        client_print_team_created(arr[0], arr[1], arr[2]);
    if (strncmp("101", msg, 3) == 0) {
        client_print_channel_created(arr[0], arr[1], arr[2]);
        client_event_channel_created(arr[0], arr[1], arr[2]);
    }
    if (strncmp("102", msg, 3) == 0)
        client_print_thread_created(arr[0], arr[1], atoi(arr[2]),
        arr[3], arr[4]);
    if (strncmp("103", msg, 3) == 0)
        client_print_reply_created(arr[0], arr[1], atoi(arr[2]), arr[3]);
    if (strncmp("104", msg, 3) == 0) {
        client_event_team_created(arr[0], arr[1], arr[2]);
        read(cli->socketfd, buffer, 1024);
    }
    if (strncmp("105", msg, 3) == 0) {
        client_event_channel_created(arr[0], arr[1], arr[2]);
        read(cli->socketfd, buffer, 1024);
    }
}

void send_create(char *msg, client_t *cli)
{
    char **arr = malloc(sizeof(char *) * 5);
    char *tmp = malloc(255);
    int i = 0;

    tmp = strtok(msg, "\"");
    while (tmp != NULL) {
        tmp = strtok(NULL, "\"");
        arr[i] = tmp;
        i++;
    }
    send_create_code(msg, cli, arr);
}