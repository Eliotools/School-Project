/*
** EPITECH PROJECT, 2020
** ls
** File description:
** Moi
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "include/phoenix.h"
#include "include/printf.h"

int show_array(char **array)
{
    int i = 0;
    while (array[i] != 0)
    {
        show_string(array[i]);
        if (array[i+1] != 0)
            my_putchar(' ');
        i++;
    }
    return (0);
}

int compare_str(char *str, char *other, int line)
{
    int i = 0;
    int k = 0;
    int j = 0;
    while (str[i] != '\0' || other[j] != '\0') {
        if (str[i] != other[j])
            k = 1;
        i++;
        j++;
    }
    if (k == 0) {
        show_string (other);
        if (line > 1)
            my_putchar(' ');
        return (1);
    }
    else
        return (0);
}

void again(int ac, char **av, DIR *other)
{
    int j = 0;
    for (int i = 1; i != ac; i++)
    {
        struct dirent *test;
        other = opendir ("./");
        while ((test = readdir(other)) != NULL) {
            j = compare_str(av[i], test->d_name, ac - i);
            if (j == 1)
                break;
        }
    }
}

void space_x(DIR *other)
{
    struct dirent *new;
    DIR *next = other;
    char **str = malloc(sizeof(char *) * 4090);
    int a = 0;

    other = next;
    while ((new = readdir(other)) != NULL) {
        if (new->d_name[0] != '.') {
            str[a] = new->d_name;
            a++;
        }
    }
    show_array(str);
}