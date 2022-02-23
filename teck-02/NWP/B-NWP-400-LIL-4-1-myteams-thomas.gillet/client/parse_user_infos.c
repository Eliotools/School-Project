/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** parse_user_infos
*/

#include "client.h"

char get_status(char *line)
{
    line = strtok(line, ">");
    line = strtok(NULL, ">");
    line = strtok(line, ",");
    line = strtok(NULL, ",");
    line = strtok(line, ":");
    line = strtok(NULL, ":");
    return (line[0]);
}

void parse_user_infos(char buffer[])
{
    char **arr = string_to_tab(buffer);
    int status;
    char *copy = malloc(512);
    
    for (int i = 1; arr[i] != NULL; i++) {
        copy = malloc(512);
        strcpy(copy, arr[i]);
        status = get_status(arr[i]) - 48;
        client_print_users(
            remove_chars(take_uuid(arr[i]), '\"'),
            remove_chars(take_name(copy), '\"'),
            status
        );
    }
}

void parse_one_user(char buffer[])
{
    int status;
    char *copy = malloc(512);

    strtok(buffer, " ");
    buffer = strtok(NULL, " ");

    printf("buffer: %s\n", buffer);
    strcpy(copy, buffer);
    status = get_status(buffer) - 48;
    client_print_user(
        remove_chars(take_uuid(buffer), '\"'),
        remove_chars(take_name(copy), '\"'),
        status
    );
}