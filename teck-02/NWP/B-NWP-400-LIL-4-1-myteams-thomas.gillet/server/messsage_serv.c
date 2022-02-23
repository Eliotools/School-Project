/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** messsage_serv
*/

#include "server.h"

void message_com(server_t *serv, int i)
{
    (void) i;
    write(serv->current_sd, "219", 3);
}