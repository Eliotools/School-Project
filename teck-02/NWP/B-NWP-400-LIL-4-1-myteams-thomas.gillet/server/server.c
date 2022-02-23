/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** server side of my_teams
*/

#include "server.h"

/**
** @brief Called when a user logins for the fisrt time to the server (/login).
** @param client_t pointer The id of the user who logged in
**
** Commands:
** /login "user_name"
**/

int main(int ac, char **av)
{
    server_t serv;

    if (ac != 2)
        return (84);
    init_serv_fs(&serv, atoi(av[1]));
    create_files();
    user_loader();
    while (TRUE) {
        setter_select(&serv);
        accept_client(&serv);
        read_commands(&serv);
    }
    return (0);
}

void user_loader(void)
{
    FILE *fp;
    char **all = string_to_tab(file_to_str(open_file("user")));
    char *tmp = malloc(20000);
    char *name;
    int line = 0;

    fp = fopen(open_file("user"), "a+");
    if (fp == NULL)
        exit(84);
    fread(tmp, 1, 20000, fp);
    for (size_t i = 0; i < strlen(tmp); i++)
        if (tmp[i] == '\n')
            line++;
    for (int i = 0; i < line; i++) {
        name = take_name(all[i]);
        server_event_user_loaded(remove_quote(get_uuid(name)),
        remove_quote(name));
    }
}

void setter_select(server_t *serv)
{
    FD_ZERO(&serv->fds);
    FD_SET(serv->server_socket, &serv->fds);
    serv->big_sd = serv->server_socket;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        serv->current_sd = serv->client_sockets[i];
        if (serv->current_sd > 0)
            FD_SET(serv->current_sd , &serv->fds);
        if (serv->current_sd > serv->big_sd)
            serv->big_sd = serv->current_sd;
    }
    if (select(serv->big_sd + 1, &serv->fds, NULL, NULL, NULL) < 0)
        printf(INFOG "select error" RESET "\n");
}

void accept_client(server_t *serv)
{
    char *message = "Hello!\n";

    if (FD_ISSET(serv->server_socket, &serv->fds)) {
        if ((serv->accept_socket = accept(serv->server_socket,
            (struct sockaddr *)&serv->addr,
            (socklen_t *)&serv->addrlength)) < 0) {
            perror("accept");
            exit(3);
        }
        write(serv->accept_socket, message, strlen(message));
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (serv->client_sockets[i] == 0) {
                serv->client_sockets[i] = serv->accept_socket;
                printf(INFOG "Adding to list of sockets as %d" RESET "\n" , i);
                break;
            }
        }
    }
}