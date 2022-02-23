/*
** EPITECH PROJECT, 2019
** main
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

void again(int ac, char **av, DIR *other);
void space_x(DIR *other);

char finding_type(int nb)
{
    if ((nb / 10000) == 1)
        return ('f');
    if ((nb / 10000) == 3)
        return ('l');
    if ((nb / 1000) == 8)
        return ('c');
    return ('?');
}

void transpho(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != 46 && str[i] != 47) {
            my_printf("%c", str[i]);
        }
        i++;
    }
}

int line(char *ac)
{
    struct stat buf;
    stat(ac, &buf);
    int error = buf.st_mode;

    if (error == 0) {
        show_string("File not found\n");
        return (84);
    }
    my_printf("Name:   ");
    transpho(ac);
    my_putchar('\n');
    my_printf("Type:   %c\n", finding_type(buf.st_mode));
    my_printf("Inode:   %i\n", buf.st_ino);
    my_printf("Hard link:   %i\n", buf.st_nlink);
    my_printf("Size:   %i\n", buf.st_size);
    my_printf("Allocated space:   %i\n", buf.st_blksize);
    return (0);
}

int first(int av, char **ac)
{
    DIR *other;
    if (av < 2)
        other = opendir ("./");
    else
        other = opendir (ac[1]);
    if (other == NULL) {
        again(av, ac, other);
        return 84;
    }
    space_x(other);

    closedir (other);
    return (0);
}

int main(int av, char **ac)
{
    if (av >= 3) {
        if (ac[1][0] == '-' && ac[1][1] == 'l')
            line (ac[2]);
        if (ac[1][0] == '-' && ac[1][1] == 'R')
            my_printf("a faire");
        if (ac[1][0] == '-' && ac[1][1] == 'r')
            my_printf("a faire");
        if (ac[1][0] == '-' && ac[1][1] == 't')
            my_printf("a faire");
        else
            first(av, ac);
    }
    else
        first(av, ac);
    return (0);
}
