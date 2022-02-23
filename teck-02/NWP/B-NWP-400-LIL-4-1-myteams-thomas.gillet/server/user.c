/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** user
*/

#include "server.h"

int count_quotes(char *line)
{
    int counter = 0;
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '\"')
            counter++;
    return (counter);
}

void user(server_t *serv, __attribute__((unused)) int i)
{
    if (count_quotes(serv->buffer) != 2) {
        write(serv->current_sd, "505", 3);
        return;
    }
    char *uuid = get_second_word(serv->buffer);
    char *line = get_line_by_uuid(uuid, open_file("user"));
    char *reply = malloc(512);

    sprintf(reply, "231 %s", line);
    write(serv->current_sd, reply, strlen(reply));
}

char *get_line_by_uuid(char *uuid, char *file)
{
    char *line;
    char *tmp = malloc(300);

    for (int i = 0; (line = get_x_line(file_to_str(file), i+1)) != NULL; i++){
        strcpy(tmp, line);
        printf("uuid => %s, compare => %s\n", take_uuid(tmp), uuid);
        if (strcmp(take_uuid(tmp), uuid) == 0) {
            free(tmp);
            return (line);
        }
    }
    free(tmp);
    return (NULL);
}

char take_status(char *line)
{
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

void users(server_t *serv, __attribute__((unused)) int i)
{
    char *line;
    char reply[2048] = {0};

    strcat(reply, "240\n");
    for (int i = 0; (line = get_x_line(file_to_str(open_file("user")), i + 1)) 
    != NULL; i++) {
        printf(INFOG "%s" RESET "\n", line);
        strcat(reply, line);
        strcat(reply, "\n");
    }
    write(serv->current_sd, reply, 2048);
    for (int j = 0; j < 2048; j++)
        reply[j] = 0;
}