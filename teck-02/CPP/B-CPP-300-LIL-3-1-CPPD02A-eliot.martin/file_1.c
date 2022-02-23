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

double  double_list_get_elem_at_front(double_list_t  list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

double  double_list_get_elem_at_back(double_list_t  list)
{
    if (list == NULL)
        return (0);
    while (list->next != NULL) {
        list = list->next;
    }
    return (list->value);
}

double  double_list_get_elem_at_position(
double_list_t  list, unsigned int position)
{
    int size = double_list_get_size(list);

    if (list == NULL || position >= size)
        return (0);
    if (position == 0)
        double_list_get_elem_at_front(list);
    for (int i = 0; i != position; i++) {
        list = list->next;
    }
    return (list->value);
}

doublelist_node_t *double_list_get_first_node_with_value(
double_list_t  list, double  value)
{
    double_list_t christoph = list;

    for (int i = 0; christoph != NULL; i++)
    {
        if (christoph->value == value)
            return (christoph);
        christoph = christoph->next;
    }
    return (NULL);
}