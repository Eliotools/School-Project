/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** messages
*/

#include "client.h"

char *take_first_uuid(char *line)
{
    char *tmp = malloc(strlen(line) + 1);

    strcpy(tmp, line);
    tmp = strtok(tmp, ":");
    tmp = strtok(NULL, ",");
    return (tmp);
}

char *take_second_uuid(char *line)
{
    char *tmp = malloc(strlen(line) + 1);

    strcpy(tmp, line);
    tmp = strtok(tmp, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ",");
    return (tmp);
}

char **get_msg_sent(char *uuid, char *other_uuid)
{
    char **msg = string_to_tab(file_to_str(open_file("private")));
    char **res = malloc(sizeof(char * ) * 128);
    char *with_quotes = malloc(39);
    int j = 0;
    sprintf(with_quotes, "\"%s\"", uuid);
    for (int i = 0; msg[i] != NULL; i++) {
        if (strcmp(take_second_uuid(msg[i]), other_uuid) == 0 &&
            strcmp(take_first_uuid(msg[i]), with_quotes) == 0) {
            res[j] = malloc(strlen(msg[i]) + 2);
            res[j] = msg[i];
            j++;
        }
    }
    res[j] = NULL;
    free(msg);
    free(with_quotes);
    return (res);
}

char **get_msg_recv(char *uuid, char *other_uuid)
{
    char **msg = string_to_tab(file_to_str(open_file("private")));
    char **res = malloc(128);
    char *with_quotes = malloc(39);
    int j = 0;
    sprintf(with_quotes, "\"%s\"", uuid);
    for (int i = 0; msg[i] != NULL; i++) {
        if (strcmp(take_second_uuid(msg[i]), with_quotes) == 0 &&
            strcmp(take_first_uuid(msg[i]), other_uuid) == 0) {
            res[j] = malloc(strlen(msg[i]) + 2);
            res[j] = msg[i];
            j++;
        }
    }
    res[j] = NULL;
    free(msg);
    free(with_quotes);
    return (res);
}