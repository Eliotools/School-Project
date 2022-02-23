/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** team
*/

#include "server.h"

void creat_zone(server_t *serv, int i)
{
    char **array = get_name_desc(serv, i);

    if (array == NULL)
        return;
    switch (serv->client_pos[i]) {
        case 0 :
            create_team_bis(serv->uuids[i], array, serv);
            break;
        case 1 :
            create_channel_bis(serv->pos_uuids[i], array, serv);
            break;
        case 2 :
            create_thread_bis(serv->pos_uuids[i], array, serv, i);
            break;
        case 3 :
            create_reply_bis(serv->pos_uuids[i], array, serv, i);
            break;
    }
}

char **get_name_desc(server_t *serv, int i)
{
    char **array = malloc(sizeof(char *) * 2);
    array[0] = malloc(MAX_NAME_LENGTH);
    array[1] = malloc(MAX_DESCRIPTION_LENGTH);
    array[0] = strtok(serv->buffer, "\"");
    array[0] = strtok(NULL, "\"");
    array[1] = strtok(NULL, "\"");
    array[1] = strtok(NULL, "\"");
    if (serv->client_pos[i] != 3)
        if (array[0] == NULL || array[1] == NULL) {
            write(serv->current_sd, "500", 3);
            return (NULL);
        }
    if (serv->client_pos[i] == 3 && array[0] == NULL) {
        write(serv->current_sd, "500", 3);
        return (NULL);
    }
    array[0] = add_quote(array[0]);
    if (array[1] == NULL) return (array);
    array[1] = add_quote(array[1]);
    return (array);
}

char *add_quote(char *str)
{
    char *final = malloc(strlen(str) + 2);

    sprintf(final, "\"%s\"", str);
    return (final);
}

int name_is_existing(char *name, char *file)
{
    char *line;

    for (int i = 0; (line = get_x_line(file_to_str(file),
        i+1)) != NULL; i++) {
        if (strcmp(take_name(line), name) == 0) {
            return (0);
        }
    }
    return (1);
}

void print_by_uuid(char *uuid, char *file, char *new_uuid)
{
    FILE *fp;
    char *line;
    char *tmp = malloc(3000);

    fp = fopen("tmp", "a+" );
    for (int i = 0; (line = get_x_line(file_to_str(file), i+1)) != NULL; i++){
        strcpy(tmp, line);
        if (strcmp(take_uuid(tmp), uuid) == 0)
            fprintf(fp, "%s%s\n", line, new_uuid);
        else
            fprintf(fp, "%s\n", line);
    }
    fclose(fp);
    remove(file);
    rename("tmp", file);
}