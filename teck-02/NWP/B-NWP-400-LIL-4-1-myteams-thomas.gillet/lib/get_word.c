/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** libs
*/

#include "server.h"

char *get_second_word(char *str)
{
    char *ptr = NULL;
    char *ptr2 = NULL;
    int len = 0;

    ptr = strtok(str, "\"");
    ptr = strtok(NULL, "\"");
    ptr2 = malloc(strlen(ptr) + 2);
    sprintf(ptr2, "\"%s\"", ptr);
    if (ptr2 != NULL) {
        len = strlen(ptr2);
        if (ptr2[len - 1] == '\n')
            ptr2[len - 1] = '\0';
    }
    return (ptr2);
}

char *get_second_word_noq(char *str)
{
    char *ptr = NULL;
    int len = 0;

    ptr = strtok(str, "\"");
    ptr = strtok(NULL, "\"");
    if (ptr != NULL) {
        len = strlen(ptr);
        if (ptr[len - 1] == '\n')
            ptr[len - 1] = '\0';
    }
    return (ptr);
}

char *get_third_word_noq(char *str)
{
    char *ptr = NULL;
    int len = 0;

    ptr = strtok(str, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    if (ptr != NULL) {
        len = strlen(ptr);
        if (ptr[len - 1] == '\n')
            ptr[len - 1] = '\0';
    }
    return (ptr);
}

char *get_fourth_word_noq(char *str)
{
    char *ptr = NULL;
    int len = 0;

    ptr = strtok(str, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    ptr = strtok(NULL, "\"");
    if (ptr != NULL) {
        len = strlen(ptr);
        if (ptr[len - 1] == '\n')
            ptr[len - 1] = '\0';
    }
    return (ptr);
}