/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** get_2
*/

#include "server.h"

char *get_line_by_name(char *name, char *file)
{
    char *line;

    for (int i = 0; (line = get_x_line(file_to_str(file), i+1)) != NULL; i++)
        if (strcmp(take_name(line), name) == 0)
            return (line);
    return (NULL);
}

char get_status(char *name)
{
    char *line = get_line_by_name(name, open_file("user"));

    if (line == NULL)
        return ('2');
    line = strtok(line, ">");
    line = strtok(NULL, ">");
    line = strtok(line, ",");
    line = strtok(NULL, ",");
    line = strtok(line, ":");
    line = strtok(NULL, ":");
    return (line[0]);
}

char *get_team(char *name)
{
    char *line = get_line_by_name(name, open_file("user"));

    if (line == NULL)
        return (NULL);
    line = strtok(line, ">");
    line = strtok(NULL, ">");
    line = strtok(line, ",");
    line = strtok(NULL, ",");
    line = strtok(NULL, ",");
    line = strtok(line, ":");
    line = strtok(NULL, ":");
    return (line);
}

char *take_time_thread(char *line)
{
    char *tmp = malloc(strlen(line));

    if (line == NULL)
        return (NULL);
    strcpy(tmp, line);
    strtok(tmp, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ":");
    tmp = strtok(NULL, ",");
    return (tmp);
}