/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** unsubscribe
*/

#include "server.h"

void file_unsub(FILE *fp, server_t *serv, char *msg, char *uuid)
{
    fclose(fp);
    remove(open_file("user"));
    rename(open_file("tmp"), open_file("user"));
    sprintf(msg, "340 %s", uuid);
    write(serv->current_sd, msg, strlen(msg));
}

void unsubscribe(server_t *serv, int i)
{
    FILE *fp;
    char *uuid = get_second_word(serv->buffer);
    char *line;
    char *tmp = malloc(300);
    int nb = teams_in_link(serv->uuids[i], remove_quote(uuid));
    char *msg = malloc(512);
    if (nb != -1) {
        fp = fopen(open_file("tmp"), "a+" );
        for (int k = 0; (line = get_x_line(file_to_str(open_file("user")),
        k+1)) != NULL; k++) {
            strcpy(tmp, line);
            if (strcmp(take_uuid(tmp), serv->uuids[i]) == 0)
                line = remove_link(line, nb);
            fprintf(fp, "%s\n", line);
        }
        file_unsub(fp, serv, msg, uuid);
        server_event_user_unsubscribed(uuid, serv->uuids[i]);
    } else {
        sprintf(msg, "345 %s", uuid);
        write(serv->current_sd, msg, strlen(msg));
    }
}

char *remove_link(char *line, int nb)
{
    char *final = malloc(strlen(line));
    int j = 0;
    int stop = 0;
    sprintf(line, "%s\n", line);
    for (int i = 0; line[i] != '\n'; i++){
        if (line[i] == '\"')
            stop++;
        if (stop == (5+(2*nb)))
            continue;
        if (line[i] == '\"' && stop-1 == (5+(2*nb)))
            continue;
        final[j] = line[i];
        j++;
    }
    return (final);
}
