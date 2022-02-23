/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myftp-eliot.martin [WSL: Ubuntu]
** File description:
** main
*/

#include "my.h"

void aches(void)
{
    printf("USAGE: ./myftp port path\n\
    port is the port number on which the server socket listens\n\
    path is the path to the home directory for the Anonymous user\n");
}

int main (int ac, char **av)
{
    if (ac < 2)
    {
        printf("wrong number of arg\n");
        aches();
        return (84);
    } if (!strcmp(av[1], "-help")) {
        aches();
        return (0);
    } if (ac != 3) {
        printf("wrong number of arg\n");
        aches();
        return (84);
    } if (!atoi(av[1])) {
        printf("av[1] should be a number ....\n");
        aches();
        return (84);
    }
    return (next(atoi(av[1]), av[2]));
}

int next(int port, char *path)
{
    my_s my_struct = create_struct(port, path);
    int pid = 0;
    int quit = 1;
    if (my_struct.error)
        return (84);
    while (1) {
        my_struct.sock_clt = accept
        (my_struct.sock_srv, (struct sockaddr *)NULL, NULL);
        if (my_struct.sock_clt < 0)
            return (84);
        write(my_struct.sock_clt, to_code("220"), strlen(to_code("220")));
        pid = fork();
        if (pid == 0) {
            pre_combat_main_phase(my_struct);
            exit;
            }
        close(my_struct.sock_clt);
    }
    return (0);
}

int my_cmp(char *str, char *cmp, int i)
{
    for (int o = 0; o != i; o++) {
    if (str[o] != cmp[o])
        return 0;}
    return 1;
}

