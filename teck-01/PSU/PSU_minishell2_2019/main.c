/*
** EPITECH PROJECT, 2024
** CPool_Day07_2019
** File description:
** Created by moi
*/

#include "my.h"

int main(int ac, char **av, char **envp)
{
    used_t used;
    char **env = envp;

    if (ac != 1)
        return (84);
    used.sup = 0;
    used.clone_in = dup(0);
    used.clone_out = dup(1);
    used.path = str_to_word_array(take_env(env, "PATH"), ':');
    next(env, used);
}

char **asking(char *printable)
{
    size_t size = BUFSIZE;
    char *buffer = NULL;
    int access = 0;
    int i;

    while (access != 2)
    {
        show_string(printable);
        i = getline(&buffer, &size, stdin);
        if (i == -1)
            exit(0);
        if (i >= 2)
            access += 1;
        buffer[i] = '\0';
        if (access == 1)
            access = check_buff(buffer);

    }
    return (clean(delet_space(buffer, ';')));
}

int check_buff(char *buffer)
{
    int i = 0;
    while ((buffer[i]))
    {
        if (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\n')
            return (2);
        i++;
    }
    return (0);
}

char *take_env(char **env, char *str)
{
    for (int i = 0; env[i]; i++)
        if (my_strcmp(env[i], str, '=') == 0) {
            return (take_after(env[i], '='));
        }
    return (NULL);
}