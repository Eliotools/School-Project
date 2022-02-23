/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** uuid_name
*/

#include "lib.h"

char *take_name(char *line)
{
    char *tmp = malloc(strlen(line) + 1);

    strcpy(tmp, line);
    tmp = strtok(tmp, ">");
    tmp = strtok(NULL, ">");
    tmp = strtok(tmp, ",");
    tmp = strtok(tmp, ":");
    tmp = strtok(NULL, ":");
    return (tmp);
}

char *gen_user_uuid(void)
{
    uuid_t binuuid;
    char *uuid = malloc(37);
    char *uuid2 = malloc(39);

    uuid_generate_random(binuuid);
    uuid_unparse_lower(binuuid, uuid);

    sprintf(uuid2, "\"%s\"", uuid);
    free(uuid);
    return (uuid2);
}

char *get_fifth_word_noq(char *str)
{
    char *ptr = NULL;
    int len = 0;

    ptr = strtok(str, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    if (ptr != NULL) {
        len = strlen(ptr);
        if (ptr[len - 1] == '\n')
            ptr[len - 1] = '\0';
    }
    return (ptr);
}

int get_time_stamp(char *line)
{
    char timestamp[9] = {0};

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == 't' && line[i + 1] == 'i' && line[i + 2] == 'm' &&
            line[i + 3] == 'e' && line[i + 4] == 's' && line[i + 5] == 't') {
                timestamp[0] = line[i + 11];
                timestamp[1] = line[i + 12];
                timestamp[2] = line[i + 13];
                timestamp[3] = line[i + 14];
                timestamp[4] = line[i + 15];
                timestamp[5] = line[i + 16];
                timestamp[6] = line[i + 17];
                timestamp[7] = line[i + 18];
                timestamp[8] = line[i + 19];
                timestamp[9] = line[i + 20];
                break;
        }
    }
    return (atoi(timestamp));
}

int get_time(char **msgsent, int j)
{
    long unsigned int time = 0;

    if (msgsent[j] != NULL)
        time = get_time_stamp(msgsent[j]);
    else
        time = 3621844267;

    return (time);
}