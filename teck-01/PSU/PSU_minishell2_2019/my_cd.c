/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include "my.h"

void my_cd_basic(char *path)
{
    if (chdir(path) == -1){
        my_printf("%s: No such file or directory.\n", path);
    }
}

void my_cd(char **env, char **buffer)
{
    int size;
    char *new = malloc(1024);
    static char *sec_pwd;
    static char *pwd;

    for (size = 0; buffer[size]; size++);
    if (check_cd(size, buffer) == 1){
        pwd = getcwd(new, 1024);
        my_cd_basic(take_env(env, "HOME"));
        return;
    } if (buffer[1][0] == '-' && len(buffer[1]) == 1){
        sec_pwd = getcwd(new, 1024);
        chdir(pwd);
        pwd = sec_pwd;
        return;
    }
    space_y(pwd, size, buffer);
    pwd = getcwd(new, 1024);
    return;

}

char *space_y(char *pwd, int size, char **buffer)
{
    if (size == 3){
        my_printf("cd: Too many arguments.\n");
        return (pwd);
    } else {

        my_cd_basic(buffer[1]);
        return (pwd);
        }
}

int check_cd(int size, char **buffer)
{
    if (size == 1)
        return (1);
    if (buffer[1][0] == '~')
        return (1);
    if (my_strcmp(buffer[1], "HOME", '\n') == 0)
        return (1);
    return (0);
}