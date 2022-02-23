/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** client_2
*/

#include "client.h"

void send_info(char *msg)
{
    char **arr = malloc(sizeof(char *) * 5);
    char *tmp = malloc(255);
    tmp = strtok(msg, "\"");

    for (int i = 0; tmp != NULL; i++) {
        tmp = strtok(NULL, "\"");
        arr[i] = tmp;
    }
    if (strncmp("280", msg, 3) == 0)
        client_print_user(arr[0], arr[1], atoi(arr[2]));
    if (strncmp("281", msg, 3) == 0)
        client_print_team(arr[0], arr[1], arr[2]);
    if (strncmp("282", msg, 3) == 0)
        client_print_channel(arr[0], arr[1], arr[2]);
    if (strncmp("283", msg, 3) == 0)
        client_print_thread(arr[0], arr[1], atoi(arr[2]), arr[3], arr[4]);
}

void send_use(char *msg)
{
    char **arr = malloc(sizeof(char *) * 5);
    char *tmp = malloc(255);
    tmp = strtok(msg, "\"");

    for (int i = 0; tmp != NULL; i++) {
        tmp = strtok(NULL, "\"");
        arr[i] = tmp;
    }
    if (strncmp("560", msg, 3) == 0)
        client_error_unknown_team(arr[0]);
    if (strncmp("561", msg, 3) == 0)
        client_error_unknown_channel(arr[0]);
    if (strncmp("562", msg, 3) == 0)
        client_error_unknown_thread(arr[0]);
}

void send_list(char *msg)
{
    char **a = malloc(sizeof(char *) * 5);
    char *tmp = malloc(255);
    tmp = strtok(msg, "\"");
    for (int i = 0; tmp != NULL; i++) {
        tmp = strtok(NULL, "\"");
        a[i] = tmp;
    }
    if (strncmp("260", msg, 3) == 0)
        for (int i = 0; a[i] != NULL; i = i + 3)
            client_print_teams(a[i], a[i + 1], a[i + 2]);
    if (strncmp("261", msg, 3) == 0)
        for (int i = 0; a[i] != NULL; i = i + 3)
            client_team_print_channels(a[i], a[i+1], a[i+2]);
    if (strncmp("262", msg, 3) == 0)
        for (int i = 0; a[i] != NULL; i = i + 5)
            client_channel_print_threads(a[i], a[i+1], atoi(a[i+2]), a[i+3],
            a[i+4]);
    if (strncmp("263", msg, 3) == 0)
        for (int i = 0; a[i] != NULL; i = i + 4)
            client_thread_print_replies(a[i], a[i+1], atoi(a[i+2]), a[i + 3]);
}

void send_sub_2(client_t *cli, char *msg, char **arr)
{
    if (strncmp("330", msg, 3) == 0)
        for (int i = 0; arr[i] != NULL; i = i+3)
            client_print_users(arr[i], arr[i + 1], atoi(arr[i + 2]));
    if (strncmp("340", msg, 3) == 0)
        client_print_unsubscribed(cli->uuid, arr[0]);
    if (strncmp("345", msg, 3) == 0)
        printf("User %s is not subscribed to %s\n", cli->uuid, arr[0]);
}

void send_sub(client_t *cli, char *msg)
{
    char **arr = malloc(sizeof(char *) * 5);
    char *tmp = malloc(255);
    tmp = strtok(msg, "\"");

    for (int i = 0; tmp != NULL; i++) {
        tmp = strtok(NULL, "\"");
        arr[i] = tmp;
    }
    if (strncmp("311", msg, 3) == 0)
        client_print_subscribed(arr[0], arr[1]);
    if (strncmp("313", msg, 3) == 0)
        printf("User %s already subscribed to %s\n", arr[0], arr[1]);
    if (strncmp("312", msg, 3) == 0)
        client_error_unknown_team(arr[0]);
    if (strncmp("320", msg, 3) == 0)
        for (int i = 0; arr[i] != NULL; i = i+3)
            client_print_teams(arr[i],  arr[i + 1],  arr[i + 2]);
    send_sub_2(cli, msg, arr);
}