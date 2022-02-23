/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** main
*/

#include "client.h"

void init_cli(client_t *cli, char *ip, int port)
{
    cli->socketfd = socket(AF_INET, SOCK_STREAM, 0);
    cli->serv_addr.sin_family = AF_INET;
    cli->serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &cli->serv_addr.sin_addr) <= 0) {
        printf(INFOG "Invalid address" RESET "\n");
        exit(84);
    }
}

int main(int ac, char **av)
{
    client_t cli;

    if (ac != 3)
        return (84);
    init_cli(&cli, av[1], atoi(av[2]));
    if (connect(cli.socketfd, (struct sockaddr *)&cli.serv_addr,
    sizeof(cli.serv_addr)) < 0) {
        printf(INFOG "Connection Failed" RESET "\n");
        return (84);
    }
    FD_ZERO(&cli.fds);
    FD_SET(cli.socketfd, &cli.fds);
    if (select(cli.socketfd + 1, &cli.fds, NULL, NULL, NULL) < 0)
        return (84);
    reply_codes(&cli);
    return (0);
}

void reply_codes(client_t *cli)
{
    char buffer[2048] = {0};
    char *cmd;

    cli->username = malloc(32);
    cli->uuid = malloc(37);

    while (read(cli->socketfd, buffer, 2048) > 0) {
        printf(INFOG "Server said: %s" RESET "\n", buffer);
        cmd = malloc(2048);
        memcpy(cmd, buffer, 2048);
        if (login_logout(cli, buffer, cmd) == 0 &&
            send_commands(cli, buffer, cmd) == 0)
            send_inputs(cli);
        for (int i = 0; i < 2048; i++)
            buffer[i] = 0;
        free(cmd);
    }
    free(cli->username);
    free(cli->uuid);
}