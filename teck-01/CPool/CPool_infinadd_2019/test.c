#include "include/my.h"
#include <stdlib.h>

void main(int ac, char **av)
{
    int i = 0;
    while (av[1][i] != '\0')
    {
        if (av[1][i] == '-') {
            my_putchar(av[1][i]);
            break;
            }
        if (av[1][i] == '%') {
            my_putchar(av[1][i]);
            break;
        }
        if (av[1][i] == '/') {
            my_putchar(av[1][i]);
            break;
        }
        if (av[1][i] == '*') {
            my_putchar(av[1][i]);
            break;
        }
        if (av[1][i] == '+') {
            my_putchar(av[1][i]);
            break;
        }
        i++;
    }
    parsing(av);
    my_putchar('\n');
}

int parsing(char **av)
{
    int    i = 0;
    int    j = 0;
    char *save = malloc(sizeof(char) *(my_strlen(av[1])));

    while (av[1][i] != '\0') {
        if (av[1][i] >= '0'  && av[1][i] <= '9') {
            save[j] = av[1][i];
            j++;
        }
        if (av[1][i] < '0' || av[1][i] > '9' || av[1][i]+1 == '\0') {
            my_put_nbr(my_strtol(save));
            j = 0;
        }
        i++;
    }
    my_putchar('\n');
    my_put_nbr(my_strtol(save));
}
