/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** setup_struct
*/

#include "server.h"

void init_serv_fs(server_t *serv, int port)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        serv->client_sockets[i] = 0;
        serv->client_pos[i] = 0;
        serv->client_log[i] = 0;
    }
    serv->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    serv->addr.sin_family = AF_INET;
    serv->addr.sin_addr.s_addr = INADDR_ANY;
    serv->addr.sin_port = htons(port);
    if (bind(serv->server_socket, (struct sockaddr *)&serv->addr,
    sizeof(serv->addr)) < 0) {
        perror("bind failed");
        exit(84);
    }
    printf(INFOG "Listening on port %d" RESET "\n", port);
    if (listen(serv->server_socket, 3) < 0)
        perror("listen");
    serv->addrlength = sizeof(serv->addr);
    printf(INFOG"Waiting for connections .." RESET "\n");
    init_serv_sd(serv);
}

void init_serv_sd(server_t *serv)
{
    serv->uuids = malloc(sizeof(char *) * MAX_CLIENTS);
    serv->pos_uuids = malloc(sizeof(char *) * MAX_CLIENTS);
    serv->usernames = malloc(sizeof(char *) * MAX_CLIENTS);

    for (int y = 0; y < MAX_CLIENTS; y++) {
        serv->pos_uuids[y] = malloc(37);
        serv->uuids[y] = malloc(37);
        serv->usernames[y] = malloc(32);
    }
}