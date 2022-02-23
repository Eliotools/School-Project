/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** day11
*/
#include "include/mylist.h"
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

int my_put_in_list(linked_list_t **list, char *data)
{
    linked_list_t *element;

    element = malloc(sizeof(*element));
    element->data = data;
    element->next = *list;
    *list = element;
    return (0);
}

linked_list_t *my_params_to_list(int ac, char** av)
{
    linked_list_t *list;
    int i = 0;
    int j = ac;

    list = NULL;
    while (j != 0) {
        my_put_in_list(&list, av[i]);
        i++;
        j--;
    }
    return(list);
}
