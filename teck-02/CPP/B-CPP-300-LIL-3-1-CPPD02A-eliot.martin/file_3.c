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


bool  double_list_add_elem_at_back(double_list_t *front_ptr , double  elem)
{
    double_list_t new = create_list(elem);
    double_list_t christoph = *front_ptr;
    int i = 0;
    if (new == NULL)
        return (false);

    if (christoph == NULL)
        return (double_list_add_elem_at_front(front_ptr, elem));

    while (christoph->next != NULL )
        christoph = christoph->next;
    christoph->next = new;
    return (true);
}

bool  double_list_add_elem_at_position(
double_list_t *front_ptr , double  elem, unsigned  int  position)
{
    doublelist_node_t *new = create_list(elem);
    double_list_t christoph = *front_ptr;

    if (position == 0) {
        return (double_list_add_elem_at_front(front_ptr, elem));
    }
    for (int i = 0; i < (position-1); i++) {
        if (christoph->next == NULL) {
            return (double_list_add_elem_at_back(front_ptr, elem));
        }
        christoph = christoph->next;
    }
    new->next = christoph->next;
    christoph->next = new;
    return (true);
}

bool  double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t christoph = *front_ptr;

    if (front_ptr == NULL)
        return (false);

    *front_ptr = christoph->next;
}

bool  double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t christoph = *front_ptr;
    int size = double_list_get_size(christoph);
    if (front_ptr == NULL)
        return (false);

    for (int i = 0; i < size - 2; i++)
        christoph = christoph->next;

    christoph->next = NULL;
    return (true);
}

bool  double_list_del_elem_at_position(
double_list_t *front_ptr , unsigned int position)
{
    double_list_t christoph = *front_ptr;
    double_list_t vasco = *front_ptr;
    int size = double_list_get_size(christoph);
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    if (position == size-1)
        return (double_list_del_elem_at_back(front_ptr));
    for (int i = 0; i < position+1; i++) {
        christoph = christoph->next;
        if (i == position-2)
            vasco = christoph;
    }
    vasco->next = christoph;
}
