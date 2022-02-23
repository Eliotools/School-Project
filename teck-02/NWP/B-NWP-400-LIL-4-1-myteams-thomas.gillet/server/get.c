/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** take
*/

#include "server.h"

char *get_uuid(char *name)
{
    char *line = get_line_by_name(name, open_file("user"));

    if (line == NULL)
        return (NULL);
    line = strtok(line, ">");
    return (line);
}

char *take_uuid(char *line)
{
    char *tmp = malloc(strlen(line));

    if (line == NULL)
        return (NULL);
    tmp = strtok(line, ">");
    return (tmp);
}

char *take_desc(char *line)
{
    char *tmp = malloc(strlen(line));

    if (line == NULL)
        return (NULL);
    strcpy(tmp, line);
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ",");
    return (tmp);
}

char *take_user_thread(char *line)
{
    char *tmp = malloc(strlen(line));

    if (line == NULL)
        return (NULL);
    strcpy(tmp, line);
    strtok(tmp, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ",");
    return (tmp);
}

char *take_time_replies(char *line)
{
    char *tmp = malloc(strlen(line));

    if (line == NULL)
        return (NULL);
    strcpy(tmp, line);
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, "\n");
    return (tmp);
}