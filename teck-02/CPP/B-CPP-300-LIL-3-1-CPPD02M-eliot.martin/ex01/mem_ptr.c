/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mem_ptr.h"

void  add_str(const  char *str1 , const  char *str2 , char **res)
{
    *res = malloc(sizeof(str1) + sizeof(str2));
    strcat(*res, str1);
    strcat(*res, str2);
}

void  add_str_struct(str_op_t *str_op)
{
    str_op->res = malloc(sizeof(str_op->str1) + sizeof(str_op->str2));
    strcat(str_op->res, str_op->str1);
    strcat(str_op->res, str_op->str2);

}
