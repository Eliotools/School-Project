/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** check_file
*/

#include "client.h"

char *take_uuid(char *line)
{
    char *tmp = malloc(strlen(line));

    if (line == NULL)
        return (NULL);
    tmp = strtok(line, ">");
    return (tmp);
}

char *check_uuid(char *uuid)
{
    char *line;
    for (int i = 0; (line = get_x_line(file_to_str(
        open_file("user")),
        i + 1)) != NULL; i++)
        if (strcmp(take_uuid(line), uuid) == 0)
            return (line);
    return (NULL);
}

char **merge_messages(char **msgsent, char **msgreceived)
{
    int nb_msg = get_nb_messages(msgreceived) + get_nb_messages(msgsent);
    char **allmsg = malloc(sizeof(char *) * (nb_msg + 1));
    long unsigned int rectime = 0;
    long unsigned int sentime = 0;
    int j = 0;
    int k = 0;
    int i = 0;
    for (i = 0; i <= nb_msg; i++) {
        sentime = get_time(msgsent, j);
        rectime = get_time(msgreceived, k);
        if (sentime < rectime) {
            allmsg[i] = msgsent[j];
            j++;
        }
        else if (rectime < sentime) {
            allmsg[i] = msgreceived[k];
            k++;
        }
    } allmsg[i - 1] = NULL;
    return (allmsg);
}