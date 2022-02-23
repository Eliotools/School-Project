/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** team
*/

#include "server.h"

void use(server_t *serv, int i)
{
    int nb = 0;
    serv->client_pos[i] = 0;
    char *tmp = malloc(strlen(serv->buffer));
    strcpy(tmp, serv->buffer);
    for (int i = 0; tmp[i] != '\n'; i++)
        if (tmp[i] == '"')
            nb++;
    nb /= 2;
    char *team = get_second_word_noq(tmp);
    strcpy(tmp, serv->buffer);
    char *chan = get_third_word_noq(tmp);
    strcpy(tmp, serv->buffer);
    char *thread = get_fourth_word_noq(tmp);
    strcpy(tmp, serv->buffer);
    char *replies = get_fifth_word_noq(tmp);
    if (team != NULL && check_law(team, serv, i) == 1) nb--;
    if (chan != NULL && check_law(chan, serv, i) == 1) nb--;
    if (thread != NULL && check_law(thread, serv, i) == 1) nb--;
    if (replies != NULL && check_law(replies, serv, i) == 1) nb--;
    if (nb == 0) write(serv->current_sd, "215", 3);
}

int check_law_2(char *pos, server_t *serv, int i)
{
    switch (serv->client_pos[i]) {
        case 2 :
            if (uuid_is_existing(pos, open_file( "thread")) == 0)
                return (move_user(serv, i, pos));
            break;
        case 3 :
            if (uuid_is_existing(pos, open_file( "replies")) == 0)
                return (move_user(serv, i, pos));
            break;
    }
    return (0);
}

int check_law(char *pos, server_t *serv, int i)
{
    char *msg = malloc(512);
    switch (serv->client_pos[i]) {
        case 0 :
            if (uuid_is_existing(pos, open_file("teams")) == 0)
                return (move_user(serv, i, pos));
            break;
        case 1 :
            if (uuid_is_existing(pos, open_file("channel")) == 0)
                return (move_user(serv, i, pos));
            break;
        default:
            if (check_law_2(pos, serv, i) == 1)
                return 1;
            break;
    }
    sprintf(msg, "56%d \"%s\"", serv->client_pos[i], pos);
    write(serv->current_sd, msg, strlen(msg));
    return (0);
}

int move_user(server_t *serv, int i, char *pos)
{
    strcpy(serv->pos_uuids[i], pos);
    serv->client_pos[i]++;
    return (1);
}

int uuid_is_existing(char *uuid, char *file)
{
    char *line;

    for (int i = 0; (line = get_x_line(file_to_str(file),
        i+1)) != NULL; i++) {
        if (strcmp(take_uuid_no_quote(line), uuid) == 0){
            return (0);
        }
    }
    return (1);
}