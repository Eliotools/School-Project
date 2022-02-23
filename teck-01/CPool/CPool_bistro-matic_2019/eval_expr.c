/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** eval_expr
*/

#include <unistd.h>
#include "include/my.h"

char *eval_expr(char *base, char *ops,
                char *av, unsigned int size)
{
    int new = 0;
    char *renew = 0;
    int i = 0;

    av = base_calc(ops, av);
    av = base_char(base, av);
    i = check_error(av);
    if (i == 84) {
        renew = my_itoa(i);
        write(2, "synthax error", 13);
        return (renew);
    }
    new = (suite(av));
    av = my_itoa(new);
    i = check_error(av);
    av = base_rev(base, av);
    renew = my_itoa(new);
    renew = base_rev(base, renew);
    return (renew);
}
