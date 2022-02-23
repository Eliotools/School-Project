#include "include/my.h"
#include <stdlib.h>

int eval_expr(char *av)
{
    char *new = find_p(av);
    int i = 0;
    char signe = '0';
    while (av[i] != '\0')
    {
        if (av[i] == '-') {
            signe = (av[i]);
            break;
            }
        if (av[i] == '%') {
            signe = (av[i]);
            break;
        }
        if (av[i] == '/') {
            signe = (av[i]);
            break;
        }
        if (av[i] == '*') {
            signe = (av[i]);
            break;
        }
        if (av[i] == '+') {
            signe = (av[i]);
            break;
        }
        i++;
    }
    i = parsing(new, signe);
    my_putchar('=');
    return(i);
}