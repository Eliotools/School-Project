/*
** EPITECH PROJECT, 2020
** main
** File description:
** Moi
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "double_list.h"

doublelist_node_t *create_list(double elem)
{
    doublelist_node_t *new = malloc(sizeof(doublelist_node_t));

    if (new == NULL)
        return (false);

    new->value = elem;
    new->next = NULL;
    return (new);
}

bool double_list_is_empty(double_list_t list)
{
    if (list == NULL) {
        return (true);
    }
    return (false);
}

unsigned int double_list_get_size(double_list_t  list)
{
    unsigned int i = 0;
    if (double_list_is_empty(list))
        return (0);
    while (list != NULL) {
        i++;
        list = list->next;
    }
    return (i);
}

void double_list_dump(double_list_t  list)
{
    int i = 0;
    while (list != NULL) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr , double  elem)
{
    doublelist_node_t *new = create_list(elem);
    if (new == NULL)
        return (false);

    new->next = *front_ptr;
    *front_ptr = new;
    return (true);
}
