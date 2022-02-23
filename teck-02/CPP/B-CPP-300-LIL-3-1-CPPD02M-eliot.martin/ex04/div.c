/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <stdio.h>
#include "castmania.h"

int integer_div(int a, int b)
{
    if (b == 0)
        return (0);
    return (a/b);
}

float decimale_div(int a, int b)
{
    if (b == 0)
        return (0);
    return ((float) a / (float) b);
}

void  exec_div(division_t *operation)
{
    integer_op_t *new;
    new = operation->div_op;
    int (*point_func[2])(int, int) = {&integer_div, &decimale_div};
    div_type_t a[2] = {INTEGER, DECIMALE};

    for (int i = 0; i <= 3; i++)
        if (operation->div_type == a[i])
            new->res = (*point_func[i])(new->a, new->b);
    operation->div_op = new;
}
int main (void)
{
    integer_op_t new;
    new.a = 10;
    new.b = 3;
    division_t *my;
    my->div_type = INTEGER;
    my->div_op = &new;
    exec_div(my);
}
