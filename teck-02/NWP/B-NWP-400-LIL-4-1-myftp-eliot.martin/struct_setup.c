/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-eliot.martin
** File description:
** structSetUp
*/

#include "my.h"

struct my_t create_struct(int port, char *path)
{
    my_s my_struct;
    my_struct.error = 0;
    if (chdir(path) == -1)
        my_struct.error = 1;
    my_struct.path = getcwd(NULL, 0);
    struct sockaddr_in server;
    struct sockaddr_in client;
    my_struct.client = client;
    if ((my_struct.sock_srv = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        my_struct.error = 1;
        return my_struct;
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    my_struct.server = server;

    return (next_struct(my_struct));
}

struct my_t next_struct(struct my_t my_struct)
{
    if (bind(my_struct.sock_srv, (struct sockaddr *)&my_struct.server
    , sizeof(my_struct.server)) < 0) {
        my_struct.error = 1;
        return my_struct;
    }
    listen(my_struct.sock_srv, 3);
    return (my_struct);
}