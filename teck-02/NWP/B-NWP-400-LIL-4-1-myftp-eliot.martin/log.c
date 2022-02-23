/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-eliot.martin
** File description:
** log
*/

#include "my.h"

struct my_t check_user(char *buffer, struct my_t my_struct)
{
    int ping = 0;
    char *pass = "Anonymous";
    write(my_struct.sock_clt, "331\n", strlen(("331\n")));
    for (int i = 0; i != strlen(buffer); i++)
    {
        if (buffer[i] == pass[ping])
            ping += 1;
    }
    if (ping == strlen(pass)) {
        my_struct.error = 1;
    }
    return (my_struct);
}

struct my_t check_pass(char *buffer, struct my_t my_struct)
{
    if (my_struct.error != 1)
        write(my_struct.sock_clt, "503\n", strlen(("503\n")));
    else if (my_cmp(buffer, "PASS ", 5))
    {
        write(my_struct.sock_clt, "230\n", strlen(("230\n")));
        my_struct.error = 2;
    }
    return (my_struct);
}

char *str_trct(char *str, int nb)
{
    char *buff = malloc(100);
    for (int i = nb; i < strlen(str); i++) {
        if (str[i] == '\n') {
            buff[i - (nb+1)] = '\0';
            break;
        }
        buff[i - nb] = str[i];
    }
    return buff;
}

int retr(struct my_t my_struct, int socket, char *buffer)
{
    int co = 0;
    FILE *file;
    char *str = malloc(100000);

    if (socket == 0)
        write(my_struct.sock_clt, "425\n", strlen(("425\n")));
    else {
        write(my_struct.sock_clt, "150\n", strlen(("150\n")));
        co = accept(socket, (struct sockaddr *)NULL, NULL);
        buffer = str_trct(buffer, 5);
        file = fopen(buffer, "r");
        if (file == NULL)
            return 0;
        fread(str, 1, 100000, file);
        write(co, str, strlen(str));
        write(co, "226", strlen(("226\n")));
        close(co);
    return (0);
    }
}

int list(struct my_t my_struct, int socket)
{
    int co = 0;
    DIR *dir;
    char *str = malloc(100);
    struct dirent *diread;
    if (socket == 0)
        write(my_struct.sock_clt, "425\n", strlen(("425\n")));
    else {
        write(my_struct.sock_clt, "150\n", strlen(("150\n")));
        co = accept(socket, (struct sockaddr *)NULL, NULL);
        if ((dir = opendir(my_struct.path)) != NULL)
            while ((diread = readdir(dir)) != NULL) {
                sprintf(str, "%s\n", diread->d_name);
                if (str[0] != '.')
                    write(co, str, strlen(str));
        }
        write(co, "226\n", strlen(("226\n")));
        close(co);
    }
    return (0);
}