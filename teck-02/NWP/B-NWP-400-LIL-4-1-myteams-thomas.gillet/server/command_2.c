/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** comand_2
*/

#include "server.h"

void set_buffer(server_t *serv, int i)
{
    int valread = 0;

    if ((valread = read(serv->current_sd , serv->buffer, 256)) > 0) {
        serv->buffer[valread] = '\0';
        printf(INFOG "Received from client %s: %s" RESET
        "\n", serv->usernames[i], serv->buffer);
    }
}