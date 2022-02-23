/*
** EPITECH PROJECT, 2021
** B-NWP-400-LIL-4-1-myteams-thomas.gillet [WSL: Ubuntu]
** File description:
** test
*/

#include "server.h"

void rewrite_file(char **line)
{
    int y = 0;
    FILE *ftemp = fopen(open_file("replace"), "w");

    if (ftemp == NULL) {
        printf(INFOG "\nUnable to open file." RESET "\n");
        exit(84);
    }
    while (line[y] != NULL) {
        fputs(line[y], ftemp);
            fputs("\n", ftemp);
        y++;
    }
    fclose(ftemp);
    remove(open_file("user"));
    rename(open_file("replace"), open_file("user"));
}

void set_statete(char *name, char state)
{
    char **line = string_to_tab(file_to_str(open_file("user")));
    char *tmp = malloc(512);
    int w = 0;

    for (int i = 0; line[i] != NULL; i++) {
        if ((strcmp(line[i], "")) == 0)
            continue;
        strcpy(tmp, line[i]);
        if (strcmp(take_name(tmp), name) == 0) {
            for (int u = 0; u < 2; w++) {
                if (line[i][w] == ':')
                    u++;
            }
            line[i][w] = state;
            break;
        }
    }
    rewrite_file(line);
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        printf(INFOG "%s" RESET "\n", array[i]);
    }
}