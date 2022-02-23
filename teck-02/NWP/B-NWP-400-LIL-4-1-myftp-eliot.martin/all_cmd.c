/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-eliot.martin
** File description:
** all_cmd
*/

#include "my.h"

char *to_code(char *code)
{
    char *str = malloc(100);
    sprintf(str, "%s <CRLF>\n", code);
    return (str);
}

int pasv_uknow(int socket)
{
    char str[100];
    my_s new = create_struct(5889, "./");
    sprintf(str, "227 <SP> (127,0,0,1,%d,%d) <CRLT>\n",23, 01);
    write(socket, str, strlen(str));
    return (new.sock_srv);
}

int post_combat_main_phase(my_s my_struct, char *buffer)
{
    static int socket = 0;
    if (my_cmp(buffer, "PASV", 4))
        socket = pasv_uknow(my_struct.sock_clt);
    if (strncmp(buffer, "CWD", 3) == 0)
        cwd(my_struct, str_trct(buffer, 4));
    if (strncmp(buffer, "CDUP", 4) == 0)
        cdup(my_struct);
    return (check_cmd(my_struct, buffer, socket));
}

int check_cmd(my_s my_struct, char *buffer, int socket)
{
    if (strncmp(buffer, "QUIT", 4) == 0) {
        write(my_struct.sock_clt, to_code("221"), strlen(to_code("221")));
        return (-1);
    }
    if (strncmp(buffer, "DELE", 4) == 0)
        dele(buffer, my_struct);
    if (strncmp(buffer, "PWD", 3) == 0)
        pwd(my_struct);
    if (strncmp(buffer, "PORT", 4) == 0)
        write(my_struct.sock_clt, to_code("200"), strlen(to_code("200")));
    if (strncmp(buffer, "RETR", 4) == 0)
        socket = retr(my_struct, socket, buffer);
    if (strncmp(buffer, "STOR", 4) == 0)
        write(my_struct.sock_clt, to_code("150"), strlen(to_code("150")));
    if (strncmp(buffer, "LIST", 4) == 0) {
        socket = list(my_struct, socket);
    }
    return (0);
}

int pre_combat_main_phase(my_s my_struct)
{
    int i = 0;
    char buffer[100];
    while (read(my_struct.sock_clt, buffer, 100) > 0) {
        if (my_cmp(buffer, "USER", 4))
            my_struct = check_user(buffer, my_struct);
        else if (my_cmp(buffer, "PASS", 4))
            my_struct = check_pass(buffer, my_struct);
        else if (my_cmp(buffer, "QUIT", 4) || i == -1) {
            write(my_struct.sock_clt, to_code("221"), strlen(to_code("221")));
            return (-1);
        }
        else if (strncmp(buffer, "NOOP", 4) == 0)
            write(my_struct.sock_clt, to_code("200"), strlen(to_code("200")));
        else if (strncmp(buffer, "HELP", 4) == 0)
            write(my_struct.sock_clt, to_code("214"), strlen(to_code("214")));
        if (my_struct.error == 2)
            i = post_combat_main_phase(my_struct, buffer);
        }
    return (0);
}
