/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include "my.h"

void next(char **env, used_t used)
{
    char **anser;
    int access = 0;

    while (1) {
        anser = asking("$>");
        access = 0;
        for (int i = 0; anser[i]; i++) {
            anser[i] = check_redirect(anser[i], &used);
            if (access != 1)
                access = bit(str_to_word_array(anser[i], ' '), env);
            if (access != 1 && anser != NULL)
                my_pid(env, used.path, str_to_word_array(anser[i], ' '));
            set_std(&used);
            anser[i] = NULL;
        }
    }
    free(anser);
}

int bit(char **str, char **env)
{
    if (my_strcmp(str[0], "exit", '\n') == 0) {
        my_exit(str);
        return (1);
    } if (my_strcmp(str[0], "setenv", '\n') == 0) {
        my_setenv(env, str);
        return (1);
    } if (my_strcmp(str[0], "unsetenv", '\n') == 0) {
        str = my_unsetenv(env, str);
        return (1);
    } if (my_strcmp(str[0], "env", '\n') == 0) {
        my_print_env(env);
        return (1);
    } if (my_strcmp(str[0], "cd", '\n') == 0) {
        my_cd(env, str);
        return (1);
    }
    return (0);
}