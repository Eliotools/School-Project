/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-eliot.martin [WSL: Ubuntu]
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <sys/wait.h>
#include <dirent.h>

void aches(void);
int my_cmp(char *str, char *cmp, int i);
int main (int ac, char **av);
int next(int port, char *path);
struct my_t create_struct(int port, char *path);
int check_cmd(struct my_t my_struct, char *buffer, int socket);
int post_combat_main_phase(struct my_t my_struct, char *buffer);
int pasv_uknow(int socket);
char *to_code(char *code);
int pre_combat_main_phase(struct my_t my_struct);
struct my_t check_user(char *buffer, struct my_t my_struct);
struct my_t check_pass(char *buffer, struct my_t my_struct);
char *str_trct(char *str, int nb);
int retr(struct my_t my_struct, int socket, char *buffer);
int list(struct my_t my_struct, int socket);
struct my_t next_struct(struct my_t my_struct);
int dele(char *buffer, struct my_t my_struct);
int pwd(struct my_t my_struct);
int cwd(struct my_t my_struct, char *buffer);
int cdup(struct my_t my_struct);

typedef struct my_t
{
    int sock_srv;
    int sock_clt;
    struct sockaddr_in server;
    struct sockaddr_in client;
    int error;
    char *path;
} my_s;
#endif /* !MY_H_ */
