/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include "printf.h"
#include "phoenix.h"

#define BUFSIZE 0

typedef struct used {
    int sup;
    int to_close;
    int clone_in;
    int clone_out;
    char **path;
} used_t;

char *double_left(char *str);
void piping(char *str, used_t *used);
char *space_z(void);
char *check_redirect(char *str, used_t *used);
char *right (char *str, used_t *used);
char *left(char *str, used_t *used);
int executor(char **arg, char **env);
int my_pid(char **envp, char **path, char **arg);
char *take_after(char *env, char c);
char *take_env(char **env, char *str);
char *del(char *str, char c);
char **verif_md(int size);
used_t init_used(char **env, used_t used);
int main(int ac, char **av, char **envp);
int check_cd(int size, char **buffer);
void next (char **env, used_t used);
char **asking(char *printable);
char *verif_m(int size);
char *double_right(char *str, used_t *used);
int check_buff(char *buffer);
char **clean(char *str);
char *delet_space(char *str, char c);
char *delet_again(char *str, char c);
void set_std(used_t *used);
void my_setenv(char **env, char **buffer);
int find_space(char *str, int i);
void mod(char **env, char **str, int i, int size);
char **my_unsetenv(char **env, char **buffer);
char *deleted(char *src, char c);
void my_cd(char **env, char **buffer);
void my_cd_basic(char *path);
char *recup_home(char **env);
int bit(char **str, char **env);
void my_print_env(char **env);
char *space_y(char *pwd, int size, char **buffer);
void my_exit(char **buffer);