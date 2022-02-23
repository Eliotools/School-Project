/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <uuid/uuid.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../libs/myteams/logging_client.h"
#include "lib.h"

typedef struct client_s {
    int socketfd;
    struct sockaddr_in serv_addr;
    char *username;
    char *uuid;
    fd_set fds;
} client_t;

char **get_msg_sent(char *uuid, char *other_uuid);
char **get_msg_recv(char *uuid, char *other_uuid);
char *take_uuid(char *line);
char *check_uuid(char *uuid);
void reply_codes(client_t *cli);
void send_msg(client_t  *cli, char *otheruuid);
char *take_first_uuid(char *line);
void send_create(char *msg, client_t *cli);
void send_list(char *msg);
void send_info(char *msg);
void send_sub(client_t *cli, char *msg);
void send_use(char *msg);
void send_inputs(client_t *cli);
int login_logout(client_t *cli, char buffer[], char *cmd);
int send_commands(client_t *cli, char buffer[], char *cmd);
int send_commands_2(client_t *cli, char buffer[]);
void parse_user_infos(char buffer[]);
void parse_one_user(char buffer[]);
char **merge_messages(char **msgsent, char **msgreceived);
int get_nb_messages(char **msg);
#endif /* !CLIENT_H_ */
