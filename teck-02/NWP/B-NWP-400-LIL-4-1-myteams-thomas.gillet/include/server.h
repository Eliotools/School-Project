/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "../libs/myteams/logging_server.h"
#include "lib.h"

#define TRUE 1
#define MAX_CLIENTS 50
#define MAX_COMMAND 18
#define BUFFER_SIZE 1000
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef struct server_s {
    int server_socket;
    int addrlength;
    int accept_socket;
    int client_sockets[MAX_CLIENTS];
    int client_pos[MAX_CLIENTS];
    int client_log[MAX_CLIENTS];
    int current_sd;
    int big_sd;
    struct sockaddr_in addr;
    fd_set fds;
    char *buffer;
    char **usernames;
    char **uuids;
    char **pos_uuids;
} server_t;

//server.c
int main(int ac, char **av);
void user_loader();
void setter_select(server_t *serv);
void accept_client(server_t *serv);
//add_to_file.c
void set_statete(char *name, char state);
void free_array(char **array);
void print_array(char **array);
//command.c
void read_commands(server_t *serv);
void commands(server_t *serv, int i, char **tab);
void send_com(server_t *serv, __attribute__((unused)) int i);
void unknown_command(server_t *serv, int i);
//command_2.c
void set_buffer(server_t *serv, int i);
//create.c
void create_team(char *team_name, char *team_description, char *uuid);
void create_channel(char *channel_name, char *channel_description,char *uuid);
int create_thread(char *thread_name, char *thread_description, char *uuid,
char *user);
int create_replies(char *replies_name, char *uuid, char *user);
void create_user(char *user_name, char *uuid);
//get.c
char *get_uuid(char *name);
char *take_uuid(char *line);
char *get_line_by_name(char *name, char *file);
char get_status(char *name);
char *get_team(char *name);
char *take_desc(char *line);
char *take_user_thread(char *line);
char *take_time_thread(char *line);
char *take_time_replies(char *line);
//log.c
void login_com(server_t *serv, int i);
void logout_com(server_t *serv, int i);
void check_exist(server_t *serv, char *uuid, char *username, int i);
//str_to_world_array.c
int my_linelen(char const *str);
int get_nbr_lines(char const *str);
char **string_to_tab(const char *str);
//send.c
void message_received(server_t *serv, int i);
char *check_uuid(char *uuid);
//team.c
void creat_zone(server_t *serv, int i);
int name_is_existing(char *name, char *file);
void print_by_uuid(char *uuid, char *file, char *new_uuid);
char **get_name_desc(server_t *serv, int i);
char *add_quote(char *str);
//team_bis.c
void create_reply_bis(char *user_uuid, char **array, server_t *serv, int i);
void create_thread_bis(char *user_uuid, char **array, server_t *serv, int i);
void create_channel_bis(char *user_uuid, char **array, server_t *serv);
void create_team_bis(char *user_uuid, char **array, server_t *serv);
char *take_uuid_no_quote(char *line);
//use.c
void use(server_t *serv, int i);
int check_law(char *pos, server_t *serv, int i);
int uuid_is_existing(char *uuid, char *file);
int move_user(server_t *serv, int i, char *pos);
//setup_struct.c
void init_serv_fs(server_t *serv, int port);
void init_serv_sd(server_t *serv);
//create_file.c
void create_file(char *filename);
void create_files(void);
//user.c
void user(server_t *serv, int i);
char *get_line_by_uuid(char *uuid, char *file);
void users(server_t *serv, __attribute__((unused)) int i);
char take_status(char *line);
int count_quotes(char *line);
//list.c
void list(server_t *serv, __attribute__((unused)) int i);
void list_team(server_t *serv);
char *get_link(char *file_fs, char *uuid);
char *take_link(char *line);
//list_bis.c
void list_replies(server_t *serv, int i);
void list_thread(server_t *serv, int i);
void list_channel(server_t *serv, int i);
//info.c
void info(server_t *serv, int i);
void info_user(server_t *serv, int i);
void info_bis(char *file, server_t *serv, int i);
//messsage_serv.c
void message_com(server_t *serv, int i);
//subscrib.c
void subscrib(server_t *serv, int i);
void subscribed(server_t *serv, int i);
void subscribed_bis(server_t *serv, int i);
char *subscribed_ter(char *line, char *uuid, char *msg);
int teams_in_link(char *user_uuid, char *teams_uuid);
//unsubscribe.c
void unsubscribe(server_t *serv, int i);
char *remove_link(char *line, int nb);
int find_uuid(char *link, char *uuid);
//help.c
void help(server_t *serv, __attribute__((unused)) int i);
#endif /* !SERVER_H_ */