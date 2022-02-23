/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-eliot.martin
** File description:
** cmb
*/

#include "my.h"

int dele(char *buffer, struct my_t my_struct)
{
    buffer = str_trct(buffer, 5);
    if (remove(buffer) == -1)
        write(my_struct.sock_clt, "550\n", strlen(("250\n")));
    else
        write(my_struct.sock_clt, "250\n", strlen(("250\n")));
    return (0);
}

int pwd(struct my_t my_struct)
{
    char cwd[999];
    char *str = malloc(999);
    write(my_struct.sock_clt, "257", strlen(("257")));
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        sprintf(str, "%s\n", cwd);
        write(my_struct.sock_clt, str, strlen(str));
    }
}

int cwd(struct my_t my_struct, char *buffer)
{
    if (chdir(buffer) != -1)
        write(my_struct.sock_clt, "250\n", strlen(("250\n")));
    else
        write(my_struct.sock_clt, "550", strlen(("550")));
    return (0);
}

int cdup(struct my_t my_struct)
{
    int nb = 0;
    nb = chdir(my_struct.path);
    if (nb == -1)
        write(my_struct.sock_clt, "550\n", strlen(("550\n")));
    else
        write(my_struct.sock_clt, "200", strlen(("200")));
    return (0);
}